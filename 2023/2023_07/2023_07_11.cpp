//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <climits>
//
//using namespace std;
//
//const int numAnts = 10;        // 蚂蚁数量
//const int numCities = 5;       // 城市数量
//const int maxIterations = 100; // 最大迭代次数
//
//const double alpha = 1.0; // 信息素重要程度因子
//const double beta = 2.0;  // 启发式因子
//const double rho = 0.5;   // 信息素蒸发因子
//
//// 城市坐标
//struct City
//{
//    double x;
//    double y;
//};
//
//vector<City> cities;                      // 城市列表
//vector<vector<double>> range;          // 城市之间的距离
//vector<vector<double>> pheromone;         // 信息素矩阵
//vector<int> bestTour;                     // 最优路径
//double bestTourLength = numeric_limits<double>::max(); // 最优路径长度
//
//// 计算两个城市之间的距离
//double calculateDistance(const City& city1, const City& city2)
//{
//    double dx = city1.x - city2.x;
//    double dy = city1.y - city2.y;
//    return sqrt(dx * dx + dy * dy);
//}
//
//// 初始化城市坐标和距离矩阵
//void initializeCities()
//{
//    cities.resize(numCities);
//    range.resize(numCities, vector<double>(numCities, 0.0));
//
//    // 设置城市坐标
//    cities[0].x = 0.0;
//    cities[0].y = 0.0;
//    cities[1].x = 1.0;
//    cities[1].y = 1.0;
//    cities[2].x = 2.0;
//    cities[2].y = 2.0;
//    cities[3].x = 3.0;
//    cities[3].y = 3.0;
//    cities[4].x = 4.0;
//    cities[4].y = 4.0;
//
//    // 计算城市之间的距离
//    for (int i = 0; i < numCities; ++i)
//    {
//        for (int j = 0; j < numCities; ++j)
//        {
//            range[i][j] = calculateDistance(cities[i], cities[j]);
//        }
//    }
//}
//
//// 初始化信息素矩阵
//void initializePheromone()
//{
//    pheromone.resize(numCities, vector<double>(numCities, 1.0));
//}
//
//// 蚂蚁类
//class Ant
//{
//public:
//    vector<int> tour;            // 当前路径
//    vector<bool> visited;        // 记录城市是否被访问过
//
//    Ant()
//    {
//        tour.resize(numCities);
//        visited.resize(numCities, false);
//    }
//
//    void clear()
//    {
//        fill(visited.begin(), visited.end(), false);
//    }
//
//    void findTour()
//    {
//        clear();
//        tour[0] = rand() % numCities;
//        visited[tour[0]] = true;
//
//        for (int i = 1; i < numCities; ++i)
//        {
//            int nextCity = chooseNextCity(tour[i - 1]);
//            tour[i] = nextCity;
//            visited[nextCity] = true;
//        }
//    }
//
//    int chooseNextCity(int currentCity)
//    {
//        double total = 0.0;
//        vector<double> probabilities(numCities, 0.0);
//
//        for (int i = 0; i < numCities; ++i)
//        {
//            if (!visited[i])
//            {
//                probabilities[i] = pow(pheromone[currentCity][i], alpha) * pow(1.0 / range[currentCity][i], beta);
//                total += probabilities[i];
//            }
//        }
//
//        double random = (double)rand() / RAND_MAX;
//        double sum = 0.0;
//        for (int i = 0; i < numCities; ++i)
//        {
//            if (!visited[i])
//            {
//                probabilities[i] /= total;
//                sum += probabilities[i];
//                if (random <= sum)
//                {
//                    return i;
//                }
//            }
//        }
//
//        return -1;
//    }
//};
//
//// 更新信息素矩阵
//void updatePheromone(vector<Ant>& ants)
//{
//    // 信息素蒸发
//    for (int i = 0; i < numCities; ++i)
//    {
//        for (int j = 0; j < numCities; ++j)
//        {
//            pheromone[i][j] *= (1.0 - rho);
//        }
//    }
//
//    // 信息素增强
//    for (const Ant& ant : ants)
//    {
//        double tourLength = 0.0;
//        for (int i = 0; i < numCities - 1; ++i)
//        {
//            int city1 = ant.tour[i];
//            int city2 = ant.tour[i + 1];
//            tourLength += range[city1][city2];
//        }
//        int lastCity = ant.tour[numCities - 1];
//        int firstCity = ant.tour[0];
//        tourLength += range[lastCity][firstCity];
//
//        // 更新路径长度最小的蚂蚁的最优路径
//        if (tourLength < bestTourLength)
//        {
//            bestTourLength = tourLength;
//            bestTour = ant.tour;
//        }
//
//        // 更新信息素
//        for (int i = 0; i < numCities - 1; ++i)
//        {
//            int city1 = ant.tour[i];
//            int city2 = ant.tour[i + 1];
//            pheromone[city1][city2] += 1.0 / tourLength;
//            pheromone[city2][city1] += 1.0 / tourLength;
//        }
//        pheromone[lastCity][firstCity] += 1.0 / tourLength;
//        pheromone[firstCity][lastCity] += 1.0 / tourLength;
//    }
//}
//
//int main()
//{
//    srand(static_cast<unsigned int>(time(0)));
//
//    initializeCities();
//    initializePheromone();
//
//    vector<Ant> ants(numAnts);
//
//    for (int iteration = 0; iteration < maxIterations; ++iteration)
//    {
//        for (int i = 0; i < numAnts; ++i)
//        {
//            ants[i].findTour();
//        }
//
//        updatePheromone(ants);
//    }
//
//    cout << "Best tour length: " << bestTourLength << endl;
//    cout << "Best tour: ";
//    for (int cityIndex : bestTour)
//    {
//        cout << cityIndex << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <cstdlib>
//#include <ctime>
//
//const int POPULATION_SIZE = 50;       // 种群大小
//const int CHROMOSOME_LENGTH = 10;     // 染色体长度
//const int MAX_GENERATIONS = 100;      // 最大迭代次数
//const double CROSSOVER_RATE = 0.8;    // 交叉概率
//const double MUTATION_RATE = 0.1;     // 变异概率
//
//// 表示一个个体（染色体）
//struct Individual {
//    std::vector<int> genes;
//    double fitness;
//
//    Individual() {
//        genes.resize(CHROMOSOME_LENGTH, 0);
//        fitness = 0.0;
//    }
//};
//
//// 初始化种群
//void initializePopulation(std::vector<Individual>& population) {
//    for (int i = 0; i < POPULATION_SIZE; ++i) {
//        for (int j = 0; j < CHROMOSOME_LENGTH; ++j) {
//            population[i].genes[j] = rand() % 2;  // 随机生成0或1
//        }
//    }
//}
//
//// 计算个体的适应度
//double calculateFitness(const Individual& individual) {
//    // 这里以一个简单的函数作为示例，目标是最大化函数 f(x) = x^2
//    int x = 0;
//    for (int i = 0; i < CHROMOSOME_LENGTH; ++i) {
//        x = (x << 1) | individual.genes[i];
//    }
//    return x * x;
//}
//
//// 选择操作
//void selection(std::vector<Individual>& population) {
//    std::vector<Individual> newPopulation(POPULATION_SIZE);
//
//    // 轮盘赌选择
//    double totalFitness = 0.0;
//    for (const Individual& individual : population) {
//        totalFitness += individual.fitness;
//    }
//
//    for (int i = 0; i < POPULATION_SIZE; ++i) {
//        double r = static_cast<double>(rand()) / RAND_MAX * totalFitness;
//        double sum = 0.0;
//        for (const Individual& individual : population) {
//            sum += individual.fitness;
//            if (sum >= r) {
//                newPopulation[i] = individual;
//                break;
//            }
//        }
//    }
//
//    population = newPopulation;
//}
//
//// 交叉操作
//void crossover(std::vector<Individual>& population) {
//    for (int i = 0; i < POPULATION_SIZE - 1; i += 2) {
//        if (static_cast<double>(rand()) / RAND_MAX < CROSSOVER_RATE) {
//            int point = rand() % (CHROMOSOME_LENGTH - 1) + 1;
//            for (int j = point; j < CHROMOSOME_LENGTH; ++j) {
//                std::swap(population[i].genes[j], population[i + 1].genes[j]);
//            }
//        }
//    }
//}
//
//// 变异操作
//void mutation(std::vector<Individual>& population) {
//    for (int i = 0; i < POPULATION_SIZE; ++i) {
//        for (int j = 0; j < CHROMOSOME_LENGTH; ++j) {
//            if (static_cast<double>(rand()) / RAND_MAX < MUTATION_RATE) {
//                population[i].genes[j] = 1 - population[i].genes[j];
//            }
//        }
//    }
//}
//
//// 打印种群中最优个体的适应度
//void printBestFitness(const std::vector<Individual>& population) {
//    double bestFitness = population[0].fitness;
//    for (int i = 1; i < POPULATION_SIZE; ++i) {
//        if (population[i].fitness > bestFitness) {
//            bestFitness = population[i].fitness;
//        }
//    }
//    std::cout << "Best Fitness: " << bestFitness << std::endl;
//}
//
//int main() {
//    srand(static_cast<unsigned int>(time(nullptr)));
//
//    std::vector<Individual> population(POPULATION_SIZE);
//
//    initializePopulation(population);
//
//    for (int generation = 0; generation < MAX_GENERATIONS; ++generation) {
//        for (int i = 0; i < POPULATION_SIZE; ++i) {
//            population[i].fitness = calculateFitness(population[i]);
//        }
//
//        printBestFitness(population);
//
//        selection(population);
//        crossover(population);
//        mutation(population);
//    }
//
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int main()
{


    printf("\n");
    system("pause");
    return 0;
}