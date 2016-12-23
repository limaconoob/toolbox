mkdir -p $PREFIX/cargo
mkdir -p $TEMP/cargo
git clone --recursive https://github.com/rust-lang/cargo $TEMP/cargo
cd $TEMP/cargo
$TEMP/cargo/configure --local-rust-root=$PREFIX/rust --prefix=$PREFIX/cargo
make -C $TEMP/cargo/ all
make -C $TEMP/cargo/ install
