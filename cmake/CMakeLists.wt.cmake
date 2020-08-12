include(ExternalProject)

ExternalProject_Add(wt
  GIT_REPOSITORY    git://github.com/kdeforche/wt.git
  GIT_TAG           master
  CMAKE_ARGS        -DCMAKE_CXX_FLAGS='-stdlib=libc++'
                    -DCMAKE_EXE_LINKER_FLAGS='-stdlib=libc++'
                    -DCMAKE_MODULE_LINKER_FLAGS='-stdlib=libc++'
                    -DWT_CPP_11_MODE='-std=c++11'
                    -DMYSQL_LIBRARY=mysqlclient -DMYSQL_PREFIX=/usr/local/Cellar/mysql-client/8.0.19
                    -DWT_WRASTERIMAGE_IMPLEMENTATION=GraphicsMagick -DGM_PREFIX=/usr/local
                    -DSSL_PREFIX=/usr/local/Cellar/openssl@1.1/1.1.1g
                    -DQt5Core_DIR=/usr/local/Cellar/qt/5.15.0
)
