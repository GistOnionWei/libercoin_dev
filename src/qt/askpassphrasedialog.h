// Copyright (c) 2011-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_ASKPASSPHRASEDIALOG_H
#define BITCOIN_QT_ASKPASSPHRASEDIALOG_H

#include <QDialog>
#include <QLabel>

class WalletModel;

namespace Ui {
    class AskPassphraseDialog;
}

/** Multifunctional dialog to ask for passphrases. Used for encryption, unlocking, and changing the passphrase.
 */
class AskPassphraseDialog : public QDialog
{
    Q_OBJECT

public:
    enum Mode {
        Encrypt,    /**< Ask passphrase twice and encrypt */
        Unlock,     /**< Ask passphrase and unlock */
        UnlockManual,
        ChangePass, /**< Ask old passphrase + new passphrase twice */
        Decrypt     /**< Ask passphrase and decrypt wallet */
    };

    explicit AskPassphraseDialog(Mode mode, QWidget *parent, QLabel *isStaking=nullptr);
    ~AskPassphraseDialog();

    void accept();

    void setModel(WalletModel *model);

    QLabel* _isStaking;

private:
    Ui::AskPassphraseDialog *ui;
    Mode mode;
    WalletModel *model;
    bool fCapsLock;

private Q_SLOTS:
    void textChanged();
    void secureClearPassFields();
    void toggleShowPassword(bool);

protected:
    bool event(QEvent *event);
    bool eventFilter(QObject *object, QEvent *event);
};

#endif // BITCOIN_QT_ASKPASSPHRASEDIALOG_H