mkdir -p $PREFIX/openssl/openssl-1.0.2f
mkdir -p $TEMP/openssl
curl -sSfL http://www.openssl.org/source/openssl-1.0.2f.tar.gz | tar zx -C $TEMP/openssl
cd $TEMP/openssl/openssl-1.0.2f
$TEMP/openssl/openssl-1.0.2f/configure darwin-i386-cc -fPIC -shared --openssldir=$PREFIX/openssl/openssl-1.0.2f --prefix=$PREFIX/openssl/openssl-1.0.2f
make -C $TEMP/openssl/openssl-1.0.2f all
lipo -create $TEMP/openssl/openssl-1.0.2f/libcrypto.1.0.0.dylib -output $PREFIX/openssl/openssl-1.0.2f/libcrypto.1.0.0.dylib
lipo -create $TEMP/openssl/openssl-1.0.2f/libssl.1.0.0.dylib -output $PREFIX/openssl/openssl-1.0.2f/libssl.1.0.0.dylib
make -C $TEMP/openssl/openssl-1.0.2f install
mkdir -p $PREFIX/rust
git clone https://github.com/rust-lang/rust.git $TEMP/rust
cd $TEMP/rust
$TEMP/rust/configure --prefix=$PREFIX/rust
make -C $TEMP/rust all
make -C $TEMP/rust install
mkdir -p $PREFIX/cargo
git clone --recursive https://github.com/rust-lang/cargo $TEMP/cargo
cd $TEMP/cargo
$TEMP/cargo/configure --local-rust-root=$PREFIX/rust --prefix=$PREFIX/cargo
make -C $TEMP/cargo/ all
make -C $TEMP/cargo/ install
