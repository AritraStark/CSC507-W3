CXX = g++
CXXFLAGS = -O2
TARGET = sort_algo
N = 50000
RUNS = 5
ALGORITHMS = MERGE QUICK RNDQUICK HEAP BUBBLE SELECTION

all: run_all

run_all:
	@mkdir -p results
	@for algo in $(ALGORITHMS); do \
		rm -f results/$$algo.txt; \
		echo "Running $$algo for $(RUNS) runs"; \
		for i in `seq 1 $(RUNS)`; do \
			SEED=$$RANDOM; \
			$(CXX) $(CXXFLAGS) -D$$algo sort_algo.cpp -o $(TARGET); \
			/usr/bin/time -f "$$algo %e %M" -o results/$$algo.txt --append ./$(TARGET) $(N) $$SEED > /dev/null; \
		done; \
	done

clean:
	rm -f sort_algo
	rm -rf results data.txt *.png
