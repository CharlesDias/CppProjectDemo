all: build_app
	@echo ""
	@echo "Done!"

build_app:
	@echo "-------------------- Build Application ----------------------"
	cmake -S . -B build
	cmake --build build -j4
	@echo ""

build_lib:
	@echo "-------------------- Build Library --------------------------"
	cmake -DBUILD_TESTS=OFF -DBUILD_APPLICATION=OFF -S . -B build
	cmake --build build --target custom_library -j4
	@echo ""

build_tests:
	@echo "-------------------- Configure and Build CMake --------------"
	cmake -DBUILD_TESTS=ON -DINCLUDE_GTEST=ON -DBUILD_APPLICATION=OFF -S . -B build
	cmake --build build -j4
	@echo ""

run:
	@echo "-------------------- Running the application ----------------"
	./build/src/app/application -h
	@echo ""

tests: build_tests
	@echo "-------------------- Running CTest --------------------------"
	GTEST_COLOR=1 ctest --test-dir build/tests --rerun-failed --output-on-failure -j4
	@echo ""

quality:
	@echo "-------------------- Running Code Quality -------------------"
	flawfinder --html --context --minlevel=1 ./src  > docs/report-flawfinder.html
	lizard --CCN 15 --length 200 --arguments 6 ./src > docs/report-lizard.txt
	@echo ""

dependency: clear
	@echo "-------------------- Create Graph Dependecy -----------------"
	cmake -DINCLUDE_GTEST=OFF -S . -B build
	cd build && cmake .. --graphviz=graph.dot && dot -Tpng graph.dot -o graph_image.png
	mkdir -p docs/images
	cp build/graph_image.png docs/images/dependency_graph.png
	@echo ""

doc: build_app
	@echo "-------------------- Build Coverage--------------------------"
	cmake --build build --target docs -j4
	@echo ""

clear:
	@echo ""
	@echo "-------------------- Clear build folder ---------------------"
	rm -rf build
	@echo ""

phony: all build_app build_lib build_tests run tests quality dependency doc clear
