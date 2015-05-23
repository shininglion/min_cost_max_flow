#include <cstdio>
#include <iostream>
#include "mcmf.h"

using namespace std;
using namespace graph;

int main(const int argc, const char* argv[])
{
	if (freopen(argv[1], "r", stdin) == nullptr) {
		fprintf(stderr, "Cannot open file %s.\n", argv[1]);
	}

	int Vnum, Enum;
	while (scanf("%d %d\n", &Vnum, &Enum) == 2) {
		if (Vnum < 1) {
			fprintf(stderr, "Invalid number of vertices: %d\n", Vnum);
			continue;
		}
		if (Enum < 0) {
			fprintf(stderr, "Invalid number of edges: %d\n", Enum);
			continue;
		}
		MCMF<int> flow_network(Vnum);

		bool fail_flag = false;
		for (int i = 0; (!fail_flag) && (i < Enum); ++i) {
			int from, to, cap, cost;
			if (scanf("%d %d %d %d", &from, &to, &cap, &cost) == 4) {
				flow_network.addPath(from - 1, to - 1, cost, cap);
			}
			else { fail_flag = true; }
		}
		if (fail_flag) {
			fprintf(stderr, "Invalid input format.\n");
			continue;
		}

		int source, sink, min_cost;
		if (scanf("%d %d", &source, &sink) != 2) {
			fprintf(stderr, "Invalid input format.\n");
			continue;
		}
		const int max_flow = flow_network.findMCMF(source - 1, sink - 1, min_cost);

		printf("max flow: %d / min cost: %d\n", max_flow, min_cost);
		for (int u = 0; u < Vnum; ++u) {
			for (int v = 0; v < Vnum; ++v) {
				const int flow = flow_network.getFlow(u, v);
				if (flow) {
					printf("flow value from %d -> %d: %d\n", u + 1, v + 1, flow);
				}
			}
		}
	}

	return 0;
}

