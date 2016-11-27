# cpptemp

C++ project template

- 画像は [Public Domain Pictures - Free Stock Photos](http://www.publicdomainpictures.net/) からもらってきた。See also [rapmocha/cc0datasets](https://github.com/rapmocha/cc0datasets).

## つかいかた

1. `git clone` or copy directory
1. `mv cpptemp ProjectName`
1. Edit CMakeLists.txt (i.e. project name, include headers directory...).
1. `cd ProjectName/build`
1. `cmake ..`
1. `cd ..`
1. start coding

`build`ディレクトリに移動して、`make`でビルド、`make run`で実行、`make cpplint`で`cpplint.py`。プロジェクトルートで`make -C build`でもいい。実行ファイル名、`cpplint.py`のパスなどはCMakeList.txtで設定。`resources`は実行ファイルと同じディレクトリに置く。buildにsimlinkを貼り、実体はプロジェクトルートにおいている。

## Make with Vim

1. `vim`
1. `:set makeprg=cd\ build&&make`
1. `:make`
1. debug
1. `:make`
1. debug
1. ...

