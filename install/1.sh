mkdir -p $PREFIX/openssl/openssl-1.0.2f
mkdir -p $TEMP/openssl
curl -sSfL http://www.openssl.org/source/openssl-1.0.2f.tar.gz | tar zx -C $TEMP/openssl
cd $TEMP/openssl/openssl-1.0.2f
$TEMP/openssl/openssl-1.0.2f/configure darwin-i386-cc -fPIC -shared --openssldir=$PREFIX/openssl/openssl-1.0.2f --prefix=$PREFIX/openssl/openssl-1.0.2f
make -C $TEMP/openssl/openssl-1.0.2f all
lipo -create $TEMP/openssl/openssl-1.0.2f/libcrypto.1.0.0.dylib -output $PREFIX/openssl/openssl-1.0.2f/libcrypto.1.0.0.dylib
lipo -create $TEMP/openssl/openssl-1.0.2f/libssl.1.0.0.dylib -output $PREFIX/openssl/openssl-1.0.2f/libssl.1.0.0.dylib
make -C $TEMP/openssl/openssl-1.0.2f install
