{-# LANGUAGE ForeignFunctionInterface #-}

module Lib where
import Foreign
import Foreign.C.Types

factorial :: CInt => x -> x

factorial x = 3 * x

foreign export ccall factorial :: (CInt x) => x -> x
