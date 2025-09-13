all::
	docker build . -t wcc-anti-debug:latest

run::
	docker run --user 0 -it wcc-anti-debug:latest bash

test::
	docker run --user 0 -it wcc-anti-debug:latest bash -c "make test"
