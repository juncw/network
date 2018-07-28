#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// 判断两个点是否存在通路
bool isPathConnect(int** network, int startX, int startY, int endX, int endY);
// 判断节点是否到每个节点都通，用node记录
void isConnectBetweenNode(int** network, int** node, int i, int j, int m, int n);
// 判断记录和已保存的节点是否一致
bool isNodeEqual(int** node1, int** node2, int m, int n);
//const int MAX_NETWORK_SIZE = 100;
int main(void) {

	// m(行), n(列)
	int m = 0, n = 0;
	// strNodeBridge 连接桥
	string strNodeBridge = "";

	cin >> m >> n;
	getchar();
	getline(cin, strNodeBridge);
	// 网络大小和输入桥的合法性检查
	if ( m < 0 || n < 0 || (m == 0 && n == 0) ) {
		cout << "Number out of range.";
		return -1;
	}
	// 申请空间和初始化
	int** network = new int*[2 * m + 1];
	// 存储节点
	int** node = new int*[m];
	int** node2 = new int*[m];
	int firstNodeX = -1, firstNodeY = -1;

	for (int i = 0; i < (2 * m + 1); ++i) {
		network[i] = new int[2 * n + 1];
	}
	for (int i = 0; i < (2 * m + 1); ++i) {
		for (int j = 0; j < (2 * n + 1); ++j) {
			// 初始化为墙
			network[i][j] = 0;
		}
	}
	for (int i = 0; i < m; ++i) {
		node[i] = new int[n];
		node2[i] = new int[n];
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			node[i][j] = 0;
			node2[i][j] = 0;
		}
	}
	

	int startX = -1, startY = -1, endX = -1, endY = -1;
	string strSelectNode = "";    // 选取节点临时变量
	bool isStartCell = false;
	for (int i = 0; i < strNodeBridge.length(); ++i) {
		if (strNodeBridge[i] == ',' && !isStartCell) {  // startX
			isStartCell = true;
			int j = 0, value = 0;
			int isNeg = 1;
			if (strSelectNode[j] == '-') {
				isNeg = -1;
				j++;
			}
			while (strSelectNode[j] != '\0') {
				if (strSelectNode[j] >= '0' && strSelectNode[j] <= '9') {
					value = value * 10 + (strSelectNode[j] - '0');
					++j;
				}
				else {
					cout << "Invalid number format." << endl;
					return -1;
				}
			}
			strSelectNode = "";
			startX = value*isNeg;
		}else if (strNodeBridge[i] == ' ') {   // startY
			int j = 0, value = 0;
			int isNeg = 1;
			if (strSelectNode[j] == '-') {
				isNeg = -1;
				j++;
			}
			while (strSelectNode[j] != '\0') {
				if (strSelectNode[j] >= '0' && strSelectNode[j] <= '9') {
					value = value * 10 + (strSelectNode[j] - '0');
					++j;
				}
				else {
					cout << "Invalid number format." << endl;
					return -1;
				}
			}
			strSelectNode = "";
			startY = value*isNeg;

		}else if (strNodeBridge[i] == ';' || strNodeBridge[i+1] == '\0') {   // endY
			int j = 0, value = 0;
			int isNeg = 1;
			if (strSelectNode[j] == '-') {
				isNeg = -1;
				j++;
			}
			while (strSelectNode[j] != '\0') {
				if (strSelectNode[j] >= '0' && strSelectNode[j] <= '9') {
					value = value * 10 + (strSelectNode[j] - '0');
					++j;
				}
				else {
					cout << "Invalid number format." << endl;
					return -1;
				}
			}
			strSelectNode = "";
			endY = value*isNeg;

			// 处理异常和路线制定
			if (startX < 0 || startY < 0 || endX < 0 || endY < 0 || startX >= m || endX >= m ||
				startY >= n || endY >= n){
				//cout << startX << " " << startY << " " << endX << " " << endY << "---";
				cout << "Number out of range." << endl;
				return -1;
			}else {
				// network连接
				if(startX == endX || startY == endY && abs(startX-endX) <= 1 || abs(startY-endY) <= 1){
					// network赋值
					if (firstNodeX == -1 && firstNodeY == -1) {
						firstNodeX = startX;
						firstNodeY = startY;
					}
					//cout << startX << " " << startY << " " << endX << " " << endY << "---\n";
					int maxX = startX > endX ? startX : endX;
					int minX = startX > endX ? endX : startX;
					int maxY = startY > endY ? startY : endY;
					int minY = startY > endY ? endY : startY;
					for (int cell_i = 2*minX+1; cell_i <= 2*maxX+1; ++cell_i) {
						for (int cell_j = 2*minY+1; cell_j <= 2*maxY+1; ++cell_j) {
							network[cell_i][cell_j] = 1;
						}
					}

					// 保存已有节点
					node[startX][startY] = 1;
					node[endX][endY] = 1;

					// 恢复
					startX = -1;
					startY = -1;
					endX = -1;
					endY = -1;

				}else {
					cout << "Incorrect command format." << endl;
					return -1;
				}
			}
		}else if (strNodeBridge[i] == ',' && isStartCell) {    // endX
			isStartCell = false;
			int j = 0, value = 0;
			int isNeg = 1;
			if (strSelectNode[j] == '-') {
				isNeg = -1;
				j++;
			}
			while (strSelectNode[j] != '\0') {
				if (strSelectNode[j] >= '0' && strSelectNode[j] <= '9') {
					value = value * 10 + (strSelectNode[j] - '0');
					++j;
				}
				else {
					cout << "Invalid number format." << endl;
					return -1;
				}
			}
			strSelectNode = "";
			endX = value*isNeg;
		}
		else if (strNodeBridge[i] >= '0' && strNodeBridge[i] <= '9' ||
			strNodeBridge[i] == '-') {
			strSelectNode += strNodeBridge[i];
		}
	}

	// 短路检测
	node2[firstNodeX][firstNodeY] = 1;
	isConnectBetweenNode(network, node2, firstNodeX, firstNodeY, m, n);
	if (!isNodeEqual(node, node2, m, n)) {
/*      for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << node[i][j] << " ";
			}
			cout << endl;
		}
*/
		cout << "Maze format error." << endl;
/*		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << node2[i][j] << " ";
			}
			cout << endl;
		}
*/
		return -1;
	}
	

	// print
	for (int i = 0; i < (2 * m + 1); ++i) {
		for (int j = 0; j < (2 * n + 1); ++j) {
			if (network[i][j] == 0) {
				cout << " [W]";
			}
			else {
				cout << " [R]";
			}
		}
		cout << endl;
	}

	// 释放空间
	for (int i = 0; i < (2 * m + 1); ++i) {
		delete[] network[i];
	}
	delete[] network;
	for (int i = 0; i < m; ++i) {
		delete[] node[i];
		delete[] node2[i];
	}
	delete[] node;
	delete[] node2;
	return 0;
}

//1,0 0,0;1,0 1,1;0,1 1,1;0,1 0,2;1,1 1,2;0,2 1,2;1,2 2,2;1,1 2,1;2,1 2,0
bool isNodeEqual(int** node1, int** node2, int m, int n) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (node1[i][j] != node2[i][j]) {
				return false;
			}
		}
	}
	return true;
}
bool isPathConnect(int** network, int startX, int startY, int endX, int endY) {
	int maxX = startX > endX ? startX : endX;
	int minX = startX > endX ? endX : startX;
	int maxY = startY > endY ? startY : endY;
	int minY = startY > endY ? endY : startY;
	for (int cell_i = 2 * minX + 1; cell_i <= 2 * maxX + 1; ++cell_i) {
		for (int cell_j = 2 * minY + 1; cell_j <= 2 * maxY + 1; ++cell_j) {
			if (network[cell_i][cell_j] != 1) {
				return false;
			}
		}
	}
	return true;
}
void isConnectBetweenNode(int** network, int** node, int i, int j, int m, int n) {
	
	if (i < 0 || j < 0 || i > m || j > n) return;
	// 上
	if (i-1 >= 0 && isPathConnect(network, i, j, i - 1, j)) {
		if (node[i - 1][j] == 0) {
			node[i - 1][j] = 1;
			isConnectBetweenNode(network, node, i - 1, j, m, n);
		}
	}
	// 下
	if (i+1 < m && isPathConnect(network, i, j, i + 1, j)) {
		if (node[i + 1][j] == 0) {
			node[i + 1][j] = 1;
			isConnectBetweenNode(network, node, i + 1, j, m, n);
		}
	}
	// 左
	if (j-1 >= 0 && isPathConnect(network, i, j, i, j - 1)) {
		if (node[i][j - 1] == 0) {
			node[i][j - 1] = 1;
			isConnectBetweenNode(network, node, i, j - 1, m, n);
		}
	}
	// 右
	if (j+1 < n && isPathConnect(network, i, j, i, j + 1)) {
		if (node[i][j + 1] == 0) {
			node[i][j + 1] = 1;
			isConnectBetweenNode(network, node, i, j + 1, m, n);
		}
	}
}