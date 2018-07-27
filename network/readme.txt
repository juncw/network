迷宫问题求解思路：

1. 获取数据
2. 检查输入数据有效性
2.1 检查输入网格大小
2.2 检查输入通路字符串异常
3. 判断通路

主要函数介绍：
// 判断两个点是否存在通路
bool isPathConnect(int** network, int startX, int startY, int endX, int endY);
// 判断节点是否到每个节点都通，用node记录
void isConnectBetweenNode(int** network, int** node, int i, int j, int m, int n);
// 判断记录和已保存的节点是否一致
bool isNodeEqual(int** node1, int** node2, int m, int n);
// 数据异常输入判断
int main(void)
