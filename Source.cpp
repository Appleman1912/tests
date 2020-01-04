using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <stack>



template <typename T>
struct Node
{
	T data;
	Node<T>* left, * right;
	Node(T data, Node<T>* left = nullptr, Node<T>* right = nullptr)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}

};

int COUNT = 5;

void print2DUtil(Node<int>* root, int space)
{
	// Base case  
	if (root == nullptr)
		return;

	// Increase distance between levels  
	space += COUNT;

	// Process right child first  
	print2DUtil(root->right, space);

	// Print current node after space  
	// count  
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->data << "\n";

	// Process left child  
	print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()  
void print2D(Node<int>* root)
{
	// Pass initial space count as 0  
	print2DUtil(root, 0);
}
int heightOfTree(Node<int>* root)
{
	if (!root)
	{
		return -1;
	}
	return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}

bool isThereNodeWithCertainValue(Node<int>* root, int data)
{
	if (!root)
	{
		return true;
	}
	return root->data == data || (isThereNodeWithCertainValue(root->left, data) || isThereNodeWithCertainValue(root->right, data));
}


int findLevel(Node<string>* root, Node<string>* dest, int level)
{
	if (!root)
	{
		return 0;
	}
	if (root == dest)
	{
		return level;
	}
	return findLevel(root->left, dest, level + 1) + findLevel(root->right, dest, level + 1);
}

int FindDist(Node<int>* root,int leftData,int rightData)
{
	if (!root)
	{
		return 0;
	}


}



void ConvertToDDL(Node<int>* root, list<int>& l)
{
	if (!root)
	{
		return;
	}
	ConvertToDDL(root->left,l);
	l.push_back(root->data);
	ConvertToDDL(root->right,l);
}

int leafCount(Node<int>* root)
{
	if (!root)
	{
		return 0;
	}
	if (!root->left && !root->right)
	{
		return 1;
	}
	else
	{
		return  leafCount(root->left) + leafCount(root->right);
	}
}




void PrintInInterval(Node<int>* root, int a, int b)
{
	if (!root)
	{
		return;
	}
	if (root->data >= a && root->data <= b)
	{
		cout << root->data << ' ';
	}
	PrintInInterval(root->left,a,b);
	PrintInInterval(root->right,a,b);
}




void PrintPath(Node<int>* root, int data)
{
	if (!root)
	{
		return;
	}
	if (root->data == data)
	{
		cout << " arrived at: " << data << endl;
		return;
	}
	cout << root->data << ' ';
	if (root->data < data)
	{
		PrintPath(root->right,data);
	}
	if (root->data > data)
	{
		PrintPath(root->left, data);
	}
}



string returnNumberOrVariable(string& exp, int index)
{
	string number="";
	while (exp[index] >= '0' && exp[index] <= 'z')
	{
		number += exp[index++];
	}
	return number;
}

bool isOperator(string& sym, int index)
{
	return sym[index] == '+' || sym[index] == '-' || sym[index] == '*';
}

Node<string>* makeTree(string& exp,int index)
{
	//int size = exp.length();
	//if (index >= size-1)
	//{
	//	return nullptr;
	//}
	//Node<string>* tree = nullptr;
	////cout << exp[index] << endl;
	//if (isOperator(exp,index))
	//{
	//	//index += 2;
	//	string val(1, exp[index]);
	//	Node<string>* temp = makeTree(exp, index + 2);
	//	return new Node<string>(val, temp);
	//	//root = new Node<string>(val, temp, temp);
	//}


	//string num = returnNumberOrVariable(exp, index);
 //   Node<string>* ptr = makeTree(exp, index + num.length() + 1);
	//return new Node<string>(num, ptr);
	//return makeTree(exp, index + num.length() + 1);


	Node<string>* root=nullptr;

	if (index >= exp.length())
	{
		return root;
	}

	if (isOperator(exp, index))
	{
		string val(1, exp[index]);
		root = new Node<string>(val);
		root->left = makeTree(exp, index + 2);
		root->right = makeTree(exp, index + 2);
	}
	else
	{
		string num = returnNumberOrVariable(exp, index);
		root = new Node<string>(num);
		root->left = makeTree(exp, index + num.length() + 1);
		root->right = makeTree(exp, index + num.length() + 1);
	}
}



//see 



bool printPath(Node<int>* root, int sum)
{
	if (sum == 0)
	{
		return true;
	}
	if (!root)
	{
		return false;
	}
	bool left = printPath(root->left, sum - root->data);
	bool right = printPath(root->right, sum - root->data);

	if (left || right)
	{
		cout << root->data << ' ';
	}
	return left || right;
}



int rootToLeafSum(Node<int>* root)
{
	if (!root)
	{
		return 0;
	}
	return max(rootToLeafSum(root->left), rootToLeafSum(root->right)) + root->data;
}



bool AreSameFromRoot(Node<int>* bigTree, Node<int>* smallTree)
{

	if (!bigTree && !smallTree)
	{
		return true;
	}
	if (!bigTree || !smallTree)
	{
		return false;
	}

	return bigTree->data == smallTree->data && AreSameFromRoot(bigTree->left, smallTree->left) && AreSameFromRoot(bigTree->right, smallTree->right);

}

bool isSubTree(Node<int>* bigTree, Node<int>* smallTree)
{
	//base cases
	
	if (!smallTree)
	{
		return true;
	}

	if (!bigTree)
	{
		return false;
	}

	if (AreSameFromRoot(bigTree, smallTree))
	{
		return true;
	}
	return isSubTree(bigTree->left, smallTree) || isSubTree(bigTree->right, smallTree);
	
}


bool isNodePresent(Node<int>* root, Node<int>* toCheck)
{
	if (!root)
	{
		return false;
	}
	if (root == toCheck)
	{
		return true;
	}
	return isNodePresent(root->left, toCheck) || isNodePresent(root->right, toCheck);
}


void getKthLargest(Node<int>* root, int& targetCount, int& curCount)
{
	if (!root || curCount >= targetCount)
	{
		return;
	}

	getKthLargest(root->right, targetCount, curCount);
	++curCount;
	if (curCount == targetCount)
	{
		cout << root->data << ' ';
		return;
	}
	getKthLargest(root->left, targetCount, curCount);
}

void getKthLargest(Node<int>* root, int& targetCount)
{
	int c = 0;
	getKthLargest(root, targetCount, c);
}

int findLevel(Node<int>* root,Node<int>* target,int level)
{
	if (!root)
		return 0;

	if (root == target)
		return level;

	int left = findLevel(root->left, target, level + 1);

	if (left != 0)
	{
		return left;
	}
	return findLevel(root->right, target, level + 1);
}





Node<int>* findlca(Node<int>* root, Node<int>* n1, Node<int>* n2)
{
	if (!root)
		return nullptr;
	if (root == n1 || root == n2)
		return root;

	Node<int>* left = findlca(root->left, n1, n2);
	Node<int>* right = findlca(root->right, n1, n2);

	if (left && right)
		return root;

	if (left)
		return left;

	if (right)
		return right;
}
//BinOrdTree
Node<int>* insert(Node<int>*& root, int data)
{

	if (!root)
	{
		return new Node<int>(data);
	}

	if (root->data < data)
	{
		root->right = insert(root->right, data);
	}
	if (root->data > data)
	{
		root->left = insert(root->left, data);
	}
	return root;
}

void builtBinOrdTree(Node<int>*& root, vector<int>& vec)
{
	for (int& element : vec)
	{
		root = insert(root, element);

	}
}


bool isLeaf(Node<int>* root)
{
	return root->left == nullptr && root->right == nullptr;
}

void printAllPathToLeaf(Node<int>* root,vector<int>& path)
{
	if (!root)
	{
		return;
	}
	path.push_back(root->data);

	if (isLeaf(root))
	{
		for (const int& v : path)
		{
			cout << v << ' ';
		}
		cout << endl;
	}
	printAllPathToLeaf(root->left, path);
	printAllPathToLeaf(root->right, path);
	path.pop_back();
}



bool PrintAnscestors(Node<int>* root,Node<int>* target)
{
	if (!root)
		return false;

	if (root == target)
		return true;

	if (PrintAnscestors(root->left, target) || PrintAnscestors(root->right, target))
	{
		cout << root->data << ' ';
		return true;
	}
	return false;


}

void addToTree(Node<int>*& root,int data)
{
	if (!root)
	{
		return;
	}
	root->data += data;
	addToTree(root->left, data);
	addToTree(root->right, data);
}



bool areSymmentric(Node<int>* leftRoot, Node<int>* rightRoot)
{
	if (!leftRoot && !rightRoot)
	{
		return true;
	}
	if (!leftRoot || !rightRoot)
	{
		return false;
	}
	return leftRoot->data == rightRoot->data && areSymmentric(leftRoot->left, rightRoot->right) && areSymmentric(leftRoot->right, rightRoot->left);
}


bool isSymmetric(Node<int>* root)
{

	if (!root)
	{
		return false;
	}
	return areSymmentric(root->left, root->right);
}


void createMirrorTree(Node<int>* root)
{
	//if (!root)
	//{
	//	return ;
	//}
	//createMirrorTree(root->left);
	//createMirrorTree(root->right);
	//swap(root->left, root->right);


	if (!root)
		return;
	createMirrorTree(root->left);
	createMirrorTree(root->right);
	swap(root->left, root->right);




	//createMirrorTree(root->left, root->right);
}
Node<int>* cmt(Node<int>* root)
{
	if (!root)
	{
		return nullptr;
	}
	return new Node<int>(root->data, cmt(root->right), cmt(root->left));
}

Node<int>* intersection(Node<int>* root1, Node<int>* root2)
{
	if (!root1 || !root2)
	{
		return nullptr;
	}
	Node<int>* result = nullptr;
	if (root1->data == root2->data)
	{
		result = new Node<int>(root1->data);
		result->left = intersection(root1->left, root2->left);
		result->right = intersection(root1->right, root2->right);
	}
	return result;
}

bool Path(Node<int>* root, Node<int>* target)
{
	if (!root)
		return false;

	if (root == target)
		return true;

	if (Path(root->left, target) || Path(root->right, target))
	{
		cout << root->data << ' ';
		return true;
	}
	return false;
}

int maxSumLeafPath(Node<int>* root)
{
	if (!root)
		return 0;
	int left = maxSumLeafPath(root->left);
	int right = maxSumLeafPath(root->right);
	return max(left, right) + root->data;
}

void kThSmallestElement(Node<int>*& root,int k,int& cur)
{
	if (!root )
		return ;



	
	 kThSmallestElement(root->left, k, cur);

	 cur++;

	 if(k == cur)
	 {
		 cout<<root->data<<endl;
		 return;
	 }


	  kThSmallestElement(root->right,k, cur);


}


int countChildren(Node<int>* root, int x, int y,int& counter)
{
	if (!root)
	{
		return 0;
	}
	if (root->left)
	{
		if (root->left->data >= x && root->left->data <= y)
		{
			++counter;
		}
	}
	if (root->right)
	{
		if (root->right->data >= x && root->right->data <= y)
		{
			++counter;
		}
	}
	countChildren(root->left, x, y, counter);
	countChildren(root->right, x, y, counter);
}

int countNodes(Node<int>* root)
{
	int counter = 0;
	if (!root)
	{
		return 0;
	}
	if (root->left)
	{
		counter+=countNodes(root->left);
	}
	if (root->right)
	{
		counter += countNodes(root->right);
	}
	return counter;
}

int sum = 0;

void Print(Node<int>* root, int x, int y)
{
	if (!root)
	{
		return;
	}
	int counter = 0;
	countChildren(root, x, y, counter);
	if (counter % 2 == 1)
	{
		cout << root->data << ' ';
		sum += root->data;
	}
	Print(root->left, x, y);
	Print(root->right, x, y);
}

int HeightOFTree(Node<int>*& root)
{
	if (!root)
	{
		return -1;
	}
	return 1 + max(HeightOFTree(root->left), HeightOFTree(root->right));
}

void PutLevelsInAVector(Node<int>* root, vector<vector<int>>& levels)
{
	queue<pair<Node<int>*, int> > q;
	levels.resize(HeightOFTree(root) + 1);
	q.push(make_pair(root, 0));


	while (!q.empty())
	{
		pair<Node<int>*, int> front = q.front();
		q.pop();
		levels[front.second].push_back(front.first->data);

		if (front.first->left)
		{
			q.push(make_pair(front.first->left,front.second+1));
		}
		if (front.first->right)
		{
			q.push(make_pair(front.first->right, front.second + 1));
		}

	}
}


void sort(vector<vector<int>>& root)
{

	for (int i = 0; i < root.size(); i++)
	{
		for (int j = 0; j < root[i].size(); j++)
		{
			for (int k = j + 1; k < root[i].size(); k++)
			{
				if (root[i][j] > root[i][k])
				{
					swap(root[i][j], root[i][k]);
				}
			}
		}
	}
}


bool compareVectors(vector<vector<int>>& vec1, vector<vector<int>>& vec2)
{
	if (vec1.size() != vec2.size())
		return false;

	int size = vec1.size();

	for (int i = 0; i < size; i++)
	{
		if (vec1[i].size() != vec2[i].size())
		{
			return false;
		}
		for (int j = 0; j < vec1[i].size(); j++)
		{
			cout << vec1[i][j] << " != " << vec2[i][j] << endl;
			if (vec1[i][j] != vec2[i][j])
				return false;
		}
	}
	return true;
}


bool areTreesEqual(Node<int>* root1, Node<int>* root2)
{
	vector<vector<int>> forRoot1,forRoot2;
	PutLevelsInAVector(root1, forRoot1);
	PutLevelsInAVector(root2, forRoot2);

	if (HeightOFTree(root1) != HeightOFTree(root2))
		return false;
	sort(forRoot1);

	sort(forRoot2);

	return compareVectors(forRoot1, forRoot2);


}

bool dfs(vector<vector<int>>& graph, int start, int toFind)
{
	stack<int> s;

	vector<bool> visited(graph.size(), false);
	if (start == toFind)
		return true;
	//visited[start] = true;
	s.push(start);


	while (!s.empty())
	{
		int cur = s.top();

		s.pop();

		if (visited[cur])
			continue;

		if (cur == toFind)
			return true;
		if (!visited[cur])
		{
			visited[cur] = true;
		}

		for (int i = 0; i < graph[cur].size(); i++)
		{
			if (! visited[graph[cur][i]])
			{
				int neighbour = graph[cur][i];
				s.push(neighbour);
			}
		}
	}
	return false;
}



bool isSymmetr(Node<int>* leftTree, Node<int>* righTree)
{
	if (!leftTree && !righTree)
		return true;
	if (!leftTree || !righTree)
		return false;

	return leftTree->data == righTree->data && isSymmetr(leftTree->left, righTree->right) && isSymmetr(leftTree->right, righTree->left);
}

bool isTreeSym(Node<int>* root)
{
	if (!root)
		return false;
	return isSymmetr(root->left, root->right);
}


void makeVertex(vector<vector<int>>& temp, int x, int y)
{
	temp[x].push_back(y);
}



void makeOppsiteGraph(vector<vector<int>>& graph,vector<vector<int> >& temp)
{
	//vector<vector<int> > temp;
	temp.resize(graph.size());

	for (int i = 0; i < graph.size(); ++i) 
	{
		for (int j = 0; j < graph[i].size(); j++)
		{
			makeVertex(temp, graph[i][j], i);
		}
	}
	return ;
}

void printGraph(const vector<vector<int> >& v)
{
	int sizemain = v.size();
	for (int i = 0; i < sizemain; i++)
	{
		int sizeSecond = v[i].size();
		cout << "i: " << i << " --> ";
		for (int j = 0; j < sizeSecond; j++)
		{
			cout <<" "<< v[i][j] << " ";
		}
		cout << endl;
	}
}


bool printAnscestor(Node<int>* root)
{
	if (!root)
		//	return 
 return true;
}


void getElements(Node<int>* root, vector<int>& storage, int curlevel, int n = 0)
{
	if (!root)
		return;
	if (n == curlevel)
		storage.push_back(root->data);
	getElements(root->left, storage, curlevel, n + 1);
	getElements(root->right, storage, curlevel, n + 1);
}




bool shouldPrint(Node<int>*& root,Node<int>*& target)
{
	if (!root)
		return false;


	if (root == target)
		return true;

	if (shouldPrint(root->left, target) || shouldPrint(root->right, target))
	{
		cout << root->data << ' ';
		return true;
	}
//	return false;

}

int countNodes(Node<int>* root, int& counter)
{
	if (!root)
		return 0;

	if (root->left)
	{
		
		++counter;
		countNodes(root->left, counter);
	}
	if (root->right)
	{
		++counter;
		countNodes(root->right, counter);
	}
	//return 0;
}





Node<int>* lcaReturner(Node<int>*& root, Node<int>*& x, Node<int>*& y)
{
	if (!root)
		return nullptr;

	if (root == x || root == y)
		return root;

	Node<int>* left = lcaReturner(root->left, x, y);
	Node<int>* right = lcaReturner(root->right, x, y);

	if (left && right)
	{
		return root;
	}
	if (left)
	{
		return left;
	}
	if (right)
	{
		return right;
	}
}




int kSmallest(Node<int>*& root, int k, int start)
{
	if (!root)
	{
		return 0;
	}



	int left = kSmallest(root->left, k + 1, start);
	if (left != 0)
	{
		return left;
	}
	if (k == start)
	{
		cout << root->data << ' ';
		return 0;
	}

	return kSmallest(root->right, k + 1, start);
	

}

Node<int>* findNode(Node<int>* root, Node<int>* target)
{
	if (!root)
	{
		return nullptr;
	}
	if (root == target)
		return root;

	Node<int>* left = findNode(root->left, target);
	if (left != nullptr)
	{
		return left;

	}

	return findNode(root->right, target);
}


void secSink(Node<int>* root)
{
	if (!root)
		return;
	if (root->left && root->left->data != 0)
	{
	//	cout << root->data << " LEFT  " << root->left->data << endl;
		swap(root->data, root->left->data);
		//cout << root->data << "   " << root->left->data << endl;
		secSink(root->left);
	}
	else if (root->right && root->right->data != 0)
	{
	//	cout << root->data << "  RIGHT " << root->right->data << endl;
		swap(root->data, root->right->data);

		secSink(root->right);
	}
	//cout << endl;
}


void mainSink(Node<int>* root)
{
	if (!root)
		return;
	mainSink(root->left);
	mainSink(root->right);

	if (root->data == 0)
	{
		secSink(root);
		cout << endl;
	}
}

int main()
{	

	vector<vector<int>> gr,t;
//	gr.resize(5);
////	t.resize(5);
//	gr[0] = { 1,3,4 };
//	//gr[1] = {};
//	gr[2] = {0};
//	gr[3] = { 2 };
//	gr[4] = { 1,3 };
//	 makeOppsiteGraph(gr,t);
//
//	printGraph(t);
//
//	cout << dfs(gr, 0, 2) << endl;

	Node<int>* root = new Node<int>(0);
	root->left = new Node<int>(1);
	root->right = new Node<int>(0);
	root->right->left = new Node<int>(0);
	root->right->right = new Node<int>(2);
	root->right->left->left = new Node<int>(3);
	root->right->left->right = new Node<int>(4);
	cout << findNode(root, root->right->left->right)->data << endl;
	//cout << lcaReturner(root, root->right->left->left, root->right->right)->data << endl;
	mainSink(root);

	print2D(root);
	///int counter = 1;
	//countNodes(root, counter);
	//cout << counter << endl;
	////shouldPrint(root, root->left->right);
	////vector<int> lev1;
	////getElements(root, lev1, 1);
	//Node<int>* root1 = new Node<int>(2);
	//root1->left = new Node<int>(4);
	//root1->right = new Node<int>(3);

	//cout << areTreesEqual(root, root1)<<endl;

	//Print(root, 3, 4);
	//cout << sum << endl;
	


	//Node<int>* root = nullptr;
	//root = new Node<int>(8);
	//root->left = new Node<int>(5);
	//root->right = new Node<int>(10);
	////vector<int> vec = { 8,5,1,7,10,12 };
	////builtBinOrdTree(root, vec);
	//vector<int> empty;
	//int cur = 0;
	// kThSmallestElement(root, 3,cur) ;
	//PrintAnscestors(root, root->right->right);
	//addToTree(root, 2);
//	createMirrorTree(root);
	//root = cmt(root);
	//Path(root, root->right->right);
//	cout << maxSumLeafPath(root);
	//print2D(root);
	return 0;
}