CHIP = bearlyml bearlyml23 robo23 examplechip

build:
	@python3 scripts/create_project.py $(CHIP_NAME)
update:
	@for name in $(CHIP); do python3 scripts/create_project.py $$name; done
