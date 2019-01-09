# !/bin/bash
mkdir -p build/striped
echo "Build started..."
"./autogen.sh"
"./configure"
make;
DIR=$PWD
echo $DIR
cp -p "$DIR/src/libercoind" "$DIR/build"
cp -p "$DIR/src/libercoin-cli" "$DIR/build"
cp -p "$DIR/src/libercoin-tx" "$DIR/build"
cp -p "$DIR/src/qt/libercoin-qt" "$DIR/build"
cp -p "$DIR/src/libercoind" "$DIR/build/striped"
cp -p "$DIR/src/libercoin-cli" "$DIR/build/striped"
cp -p "$DIR/src/libercoin-tx" "$DIR/build/striped"
cp -p "$DIR/src/qt/libercoin-qt" "$DIR/build/striped"
strip "$DIR/build/striped/libercoind"
strip "$DIR/build/striped/libercoin-cli"
strip "$DIR/build/striped/libercoin-tx"
strip "$DIR/build/striped/libercoin-qt"
echo "Build finished."
