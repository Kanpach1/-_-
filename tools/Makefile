# コンパイラ設定
CC = gcc
CFLAGS = -Wall -Wextra -lm
BIN_DIR = bin
SRC_DIR = src
DOC_DIR = docs

# ヘルプターゲット
help:
	@echo "使用可能なコマンド:"
	@echo "  make help            : このヘルプを表示します。"
	@echo "  make create N=<名前> : 指定した名前で .c ファイルと .md ファイルを生成します。"
	@echo "  make build N=<名前>  : 指定した名前の .c ファイルをコンパイルします。"
	@echo "  make run N=<名前>    : 指定した名前の .c ファイルを実行します。"
	@echo "  make clean           : bin ディレクトリを削除します。"

# ファイル生成ターゲット
create:
	@if [ "$(N)" = "" ]; then \
		echo "❌ N=<ファイル名> を指定してください。例: make create N=example"; \
		exit 1; \
	fi; \
	C_FILE=$(SRC_DIR)/$(N).c; \
	MD_FILE=$(DOC_DIR)/$(N).md; \
	mkdir -p $(SRC_DIR) $(DOC_DIR); \
	if [ ! -f "$$C_FILE" ]; then \
		echo "/*" > "$$C_FILE"; \
		echo " * $$C_FILE" >> "$$C_FILE"; \
		echo " * このファイルは $(N) のテンプレートです。" >> "$$C_FILE"; \
		echo " */" >> "$$C_FILE"; \
		echo "✅ $$C_FILE を生成しました。"; \
	else \
		echo "❌ $$C_FILE は既に存在します。"; \
	fi; \
	if [ ! -f "$$MD_FILE" ]; then \
		echo "# $(N)" > "$$MD_FILE"; \
		echo "" >> "$$MD_FILE"; \
		echo "このファイルは演習問題に対応します。" >> "$$MD_FILE"; \
		echo "✅ $$MD_FILE を生成しました。"; \
	else \
		echo "❌ $$MD_FILE は既に存在します。"; \
	fi

# ビルドターゲット
build:
	@if [ "$(N)" = "" ]; then \
		echo "❌ N=<ファイル名> を指定してください。例: make build N=example"; \
		exit 1; \
	fi; \
	C_FILE=$(SRC_DIR)/$(N).c; \
	EXEC_FILE=$(BIN_DIR)/$(N).exe; \
	if [ ! -f "$$C_FILE" ]; then \
		echo "❌ $$C_FILE が存在しません。先に make create N=$(N) を実行してください。"; \
		exit 1; \
	fi; \
	mkdir -p $(BIN_DIR); \
	$(CC) $(CFLAGS) -o "$$EXEC_FILE" "$$C_FILE"; \
	echo "✅ ビルド成功: $$EXEC_FILE"

# 実行ターゲット
run:
	@if [ "$(N)" = "" ]; then \
		echo "❌ N=<ファイル名> を指定してください。例: make run N=example"; \
		exit 1; \
	fi; \
	EXEC_FILE=$(BIN_DIR)/$(N).exe; \
	if [ -f "$$EXEC_FILE" ]; then \
		echo "🚀 実行中: $$EXEC_FILE"; \
		"./$$EXEC_FILE"; \
	else \
		echo "❌ 実行ファイルが見つかりません: $$EXEC_FILE"; \
	fi

# クリーンアップターゲット
clean:
	rm -rf $(BIN_DIR)
	echo "🧹 bin ディレクトリを削除しました。"
