all:
	@make -sC build
.PHONY: all

clean:
	@make clean -sC build
.PHONY: clean

test:
	@make test -sC build
.PHONY: test

lint:
	@make lint -sC build
.PHONY: lint
