#!/bin/bash

# ビルド用ディレクトリを確認・作成
BUILD_DIR="./build"
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

# excercises 内のすべての .c ファイルをビルド
find excercises -name "*.c" | while read c_file; do
    # 実行ファイル名を生成 (例: 1-2_1.c -> build/1-2_1)
    base_name=$(basename "$c_file" .c)
    gcc "$c_file" -o "$BUILD_DIR/$base_name"
    echo "Compiled $c_file -> $BUILD_DIR/$base_name"
done

echo "ビルドが完了しました！すべての実行ファイルは $BUILD_DIR に保存されています。"
