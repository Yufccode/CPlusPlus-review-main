

#include "Graph.hpp"
#include <string.h>

void test1()
{
    // 测试邻接矩阵的表示方法
    yufc_graph_matrix::graph<char, int, INT_MAX, true> g("0123", 4);
    g.add_edge('0', '1', 1);
    g.add_edge('0', '3', 4);
    g.add_edge('1', '3', 2);
    g.add_edge('1', '2', 9);
    g.add_edge('2', '3', 8);
    g.add_edge('2', '1', 5);
    g.add_edge('2', '0', 3);
    g.add_edge('3', '2', 6);
    g.print();
}

void test2()
{
    // 测试邻接矩阵的表示方法
    yufc_graph_link_table::graph<char, int, true> g("0123", 4);
    g.add_edge('0', '1', 1);
    g.add_edge('0', '3', 4);
    g.add_edge('1', '3', 2);
    g.add_edge('1', '2', 9);
    g.add_edge('2', '3', 8);
    g.add_edge('2', '1', 5);
    g.add_edge('2', '0', 3);
    g.add_edge('3', '2', 6);
    g.print();
}

template <class graph_type>
void make_graph(graph_type &g)
{
    // 后面就用这个图来测试了
    g.add_edge('A', 'B', 1);
    g.add_edge('B', 'C', 1);
    g.add_edge('C', 'A', 1);
    g.add_edge('A', 'D', 1);
    g.add_edge('D', 'F', 1);
    g.add_edge('C', 'F', 1);
    g.add_edge('F', 'H', 1);
    g.add_edge('H', 'I', 1);
    g.add_edge('B', 'E', 1);
    g.add_edge('G', 'E', 1);
}
void test3()
{
    // 测试bfs
    yufc_graph_matrix::graph<char, int, false> g("ABCDEFGHI", 9); // 无向图
    make_graph(g);
    g.print();
    std::cout << std::endl;
    g.bfs('A');
}
void test4()
{
    // 测试dfs
    yufc_graph_matrix::graph<char, int, false> g("ABCDEFGHI", 9); // 无向图
    make_graph(g);
    g.print();
    std::cout << std::endl;
    g.dfs('A');
}
void test5()
{
    // 测试克鲁斯卡尔算法
    const char *str = "abcdefghi";
    yufc_graph_matrix::graph<char, int> g(str, strlen(str));
    g.add_edge('a', 'b', 4);
    g.add_edge('a', 'h', 8);
    // g.AddEdge('a', 'h', 9);
    g.add_edge('b', 'c', 8);
    g.add_edge('b', 'h', 11);
    g.add_edge('c', 'i', 2);
    g.add_edge('c', 'f', 4);
    g.add_edge('c', 'd', 7);
    g.add_edge('d', 'f', 14);
    g.add_edge('d', 'e', 9);
    g.add_edge('e', 'f', 10);
    g.add_edge('f', 'g', 2);
    g.add_edge('g', 'h', 1);
    g.add_edge('g', 'i', 6);
    g.add_edge('h', 'i', 7);
    // 这个图就是课件上，算法导论上那个图
    yufc_graph_matrix::graph<char, int> kminTree;
    std::cout << "Kruskal:" << g.Kruskal(kminTree) << std::endl;
    kminTree.print();
    std::cout << "------------------------------------------" << std::endl;
    yufc_graph_matrix::graph<char, int> kminTree2;
    std::cout << "Prim: " << g.Prim(kminTree2, 'a') << std::endl;
    kminTree2.print();
}

void test6()
{
    // 测试迪杰斯特拉
    const char *str = "syztx";
    yufc_graph_matrix::graph<char, int, INT_MAX, true> g(str, strlen(str));
    g.add_edge('s', 't', 10);
    g.add_edge('s', 'y', 5);
    g.add_edge('y', 't', 3);
    g.add_edge('y', 'x', 9);
    g.add_edge('y', 'z', 2);
    g.add_edge('z', 's', 7);
    g.add_edge('z', 'x', 6);
    g.add_edge('t', 'y', 2);
    g.add_edge('t', 'x', 1);
    g.add_edge('x', 'z', 4);
    std::vector<int> dist;
    std::vector<int> parentPath;
    g.Dijkstra('s', dist, parentPath);
    g.print_short_path('s', dist, parentPath);
}
void test7()
{
    const char *str = "syztx";
    yufc_graph_matrix::graph<char, int, INT_MAX, true> g(str, strlen(str));
    g.add_edge('s', 't', 6);
    g.add_edge('s', 'y', 7);
    g.add_edge('y', 'z', 9);
    g.add_edge('y', 'x', -3);
    g.add_edge('z', 's', 2);
    g.add_edge('z', 'x', 7);
    g.add_edge('t', 'x', 5);
    g.add_edge('t', 'y', 8);
    g.add_edge('t', 'z', -4);
    g.add_edge('x', 't', -2);
    std::vector<int> dist;
    std::vector<int> parentPath;
    if (g.BellManFord('s', dist, parentPath))
        g.print_short_path('s', dist, parentPath);
    else
        std::cout << "There is a negative weight circuit present" << std::endl;
}
void test8()
{
    // 测试弗洛伊德算法
    const char *str = "12345";
    yufc_graph_matrix::graph<char, int, INT_MAX, true> g(str, strlen(str));
    g.add_edge('1', '2', 3);
    g.add_edge('1', '3', 8);
    g.add_edge('1', '5', -4);
    g.add_edge('2', '4', 1);
    g.add_edge('2', '5', 7);
    g.add_edge('3', '2', 4);
    g.add_edge('4', '1', 2);
    g.add_edge('4', '3', -5);
    g.add_edge('5', '4', 6);
    std::vector<std::vector<int>> vvDist;
    std::vector<std::vector<int>> vvParentPath;
    g.FloydWarshall(vvDist, vvParentPath);
    // 打印任意两点之间的最短路径
    for (size_t i = 0; i < strlen(str); ++i)
    {
        g.print_short_path(str[i], vvDist[i], vvParentPath[i]);
        std::cout << std::endl;
    }
}

int main()
{
    test8();
    return 0;
}