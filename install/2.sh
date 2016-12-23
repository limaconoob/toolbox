mkdir -p $PREFIX/rust
git clone https://github.com/rust-lang/rust.git $TEMP/rust
cd $TEMP/rust
$TEMP/rust/configure --prefix=$PREFIX/rust
make -C $TEMP/rust all
make -C $TEMP/rust install
