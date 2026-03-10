{-# LANGUAGE CPP #-}
{-# LANGUAGE NoRebindableSyntax #-}
{-# OPTIONS_GHC -fno-warn-missing-import-lists #-}
module Paths_llvm_test (
    version,
    getBinDir, getLibDir, getDynLibDir, getDataDir, getLibexecDir,
    getDataFileName, getSysconfDir
  ) where

import qualified Control.Exception as Exception
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude

#if defined(VERSION_base)

#if MIN_VERSION_base(4,0,0)
catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
#else
catchIO :: IO a -> (Exception.Exception -> IO a) -> IO a
#endif

#else
catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
#endif
catchIO = Exception.catch

version :: Version
version = Version [0,1,0,0] []
bindir, libdir, dynlibdir, datadir, libexecdir, sysconfdir :: FilePath

bindir     = "/workspaces/0-installation/llvm_hs/.stack-work/install/aarch64-linux/7f3ed0f254197fb13df5692b73c57099cc029ebecbaa63b22d3fe9fd34061a69/8.10.7/bin"
libdir     = "/workspaces/0-installation/llvm_hs/.stack-work/install/aarch64-linux/7f3ed0f254197fb13df5692b73c57099cc029ebecbaa63b22d3fe9fd34061a69/8.10.7/lib/aarch64-linux-ghc-8.10.7/llvm-test-0.1.0.0-9DrUCt0QGdPAo63yYcCJ1S-toy"
dynlibdir  = "/workspaces/0-installation/llvm_hs/.stack-work/install/aarch64-linux/7f3ed0f254197fb13df5692b73c57099cc029ebecbaa63b22d3fe9fd34061a69/8.10.7/lib/aarch64-linux-ghc-8.10.7"
datadir    = "/workspaces/0-installation/llvm_hs/.stack-work/install/aarch64-linux/7f3ed0f254197fb13df5692b73c57099cc029ebecbaa63b22d3fe9fd34061a69/8.10.7/share/aarch64-linux-ghc-8.10.7/llvm-test-0.1.0.0"
libexecdir = "/workspaces/0-installation/llvm_hs/.stack-work/install/aarch64-linux/7f3ed0f254197fb13df5692b73c57099cc029ebecbaa63b22d3fe9fd34061a69/8.10.7/libexec/aarch64-linux-ghc-8.10.7/llvm-test-0.1.0.0"
sysconfdir = "/workspaces/0-installation/llvm_hs/.stack-work/install/aarch64-linux/7f3ed0f254197fb13df5692b73c57099cc029ebecbaa63b22d3fe9fd34061a69/8.10.7/etc"

getBinDir, getLibDir, getDynLibDir, getDataDir, getLibexecDir, getSysconfDir :: IO FilePath
getBinDir = catchIO (getEnv "llvm_test_bindir") (\_ -> return bindir)
getLibDir = catchIO (getEnv "llvm_test_libdir") (\_ -> return libdir)
getDynLibDir = catchIO (getEnv "llvm_test_dynlibdir") (\_ -> return dynlibdir)
getDataDir = catchIO (getEnv "llvm_test_datadir") (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "llvm_test_libexecdir") (\_ -> return libexecdir)
getSysconfDir = catchIO (getEnv "llvm_test_sysconfdir") (\_ -> return sysconfdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "/" ++ name)
