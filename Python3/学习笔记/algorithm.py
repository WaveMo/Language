#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# @Date    : 2018-04-09 13:03:04
# @Author  : mohailang (1198534595@qq.com)


# 在 Python 里，用 list对象以及其方法就可以简单实现堆栈和队列了
# 但为了理解，还是用 Python 来模拟具体实现这两种数据结构
# 栈的例子(具有反转属性)：匹配符号、浏览器回退、十进制转换为二进制
# 队列的例子：模拟烫山芋游戏(围成圆圈)
# -*- 队列、堆栈 begin -*-
# 队列
class Queue(object):
    """队列类: 先进先出"""

    def __init__(self):
        self.items = []

    def enqueue(self, item):
        """入队"""
        self.items.append(item)

    def dequeue(self):
        """出队"""
        self.items.pop(0)

    def size(self):
        """队列大小"""
        return len(self.items)

    def isEmpty(self):
        """判断队列是否为空"""
        return self.size() == 0


# 栈
class Stack (object):
    """栈类: 后进先出"""

    def __init__(self):
        self.items = []

    def push(self, item):
        """ 压栈"""
        self.items.append(item)

    def pop(self):
        """出栈"""
        return self.items.pop()

    def size(self):
        """栈大小"""
        return len(self.items)

    def top(self):
        """返回栈顶元素"""
        return self.items[self.size()-1]

    def isEmpty(self):
        """判断栈是否为空"""
        return self.size() == 0


# 双端队列(回文检查)
class deque(object):
    """双端队列"""

    def __init__(self):
        self.items = []

    def isEmpty(self):
        return self.items == []

    def addRear(self, item):
        self.items.insert(0, item)

    def addFront(self, item):
        self.items.append(item)

    def removeRear(self):
        self.items.pop(0)

    def removeFront(self):
        self.items.pop()

    def size(self):
        return len(self.items)
# -*- 栈、队列 end -*-


# -*- 递归 begin-*-
# 用栈帧来实现递归，每次递归都会为函数的本地变量创建一个作用域
# 汉诺塔
def move(n, from, buffer, to):
    if n == 1:
        print("move", n, "from", from, "to", to)
    else:
        move(n-1, from, to, buffer)
        move(1, from, buffer, to)
        move(n-1, buffer, from, to)


# 递归解决硬币找零问题
def solveCoins(coinValueList, change):
    minCoins = change
    if change in coinValueList:
        return 1
    for i in [c for c in coinValueList if c < change]:
        numCoins = 1+solveCoins(coinValueList, change-i)
        if minCoins > numCoins:
            minCoins = numCoins
    return numCoins

# -*- 递归 end-*-


# -*- 链表 begin -*-
# 定义链表节点类
class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None

    def getData(self):
        return self.data

    def getNext(self):
        return self.next

    def setData(self, newData):
        self.data = newData

    def setNext(self, newNext):
        self.next = newNext


# 定义链表操作类(所有节点都先经过 Node 类处理过)
class LinkedList(object):
    # 初始化一个头结点
    def __init__(self, head):
        self.head = head

    # 获取链表的长度
    def getLen(self):
        length = 0
        temp = self.head
        while temp is not None:
            length += 1
            temp = temp.next
        return length

    # 追加节点(传进来的是一个处理过的节点)（有序）
    def add(self, node):
        temp = self.head
        while temp.next is not None:
            temp = temp.next
        temp.next = node

    # 这里还有一种时间复杂度更小的做法：每次添加节点都是追加载头结点的前面，新节点作为新的头结点（无序）
    def add(self, item):
        node = Node(item)
        node.setNext(self.head)
        self.head = node

    # 删除节点(关键是找到要删除节点的前一个节点)

    def delete(self, index):
        if index < 1 or index > self.getLen():
            print("index is out of range")
            return False
        # 如果删除的是头结点
        if index == 1:
            self.head = self.head.next
        position = 0
        temp = self.head
        while temp is not None:
            position += 1
            if position == index-1:
                temp.next = temp.next.next
                break
            temp = temp.next

    # 插入节点
    def insert(self, index, node):
        if index < 1 or index > self.getLen():
            print("index is out of range")
            return False
        position = 0
        temp = self.head
        while temp is not None:
            position += 1
            if position == index-1:
                node.next = temp.next
                temp.next = node
                break
            temp = temp.next

    # 打印链表
    def printList(self, head):
        lists = []
        while head is not None:
            lists.append(head.getData())
            head = head.next
        return lists

    # 反转链表
    def listReverse(self, head):
        if head.next is None:
            return head
        pre = head
        cur = head.next
        while cur is not None:
            # 断链前先保存后面的节点
            temp = cur.next
            # 断链，把当前节点指向前一个节点
            cur.next = pre
            # 把节点不断往后移一位，把当前节点作为下一次的前一个节点，把后一个节点作为下次的当前节点，不断迭代
            pre = cur
            cur = temp
        head.next = None
        # 返回反转后的头结点
        return pre


if __name__ == '__main__':
    print("\n链表:")
    head = Node("head")
    linked_list = LinkedList(head)
    for i in range(10):
        node = Node(i)
        linked_list.add(node)
    print(linked_list.printList(head))
    linked_list.delete(5)
    print(linked_list.printList(head))
    a = Node("add")
    linked_list.add(a)
    print(linked_list.printList(head))
    node = Node("insert")
    linked_list.insert(4, node)
    print(linked_list.printList(head))
    head = linked_list.listReverse(head)
    print(linked_list.printList(head))


# -*- 链表 end -*-


# -* 图 begin -*
a, b, c, e, f = range(5)
# 邻接列表
N = [
    [b, c],
    [a, c],
    [a, b, e, f],
    [c, f],
    [c, e]
]
# 加权邻接字典
N = [
    {'b': 2, 'c': 3, 'f': 2},   # a
    {'a': 2, 'c': 2},  # b
    {'a': 3, 'b': 2, 'e': 4, 'f': 3},  # c
    {'c': 4, 'f': 5},  # e
    {'c': 3, 'e': 5}  # f
]
# 邻接集的字典表示法
N = {
    'a': set('bc'),
    'b': set('a,c'),
    'c': set('a,b,e,f'),
    'e': set('c,f'),
    'f': set('c,e')
}
# 邻接矩阵(用1和0来表示相关节点是否为当前节点的邻居)
N = [
    [0, 1, 1, 0, 1],
    [1, 0, 1, 0, 0],
    [1, 1, 0, 1, 1],
    [0, 0, 1, 0, 1],
    [0, 0, 1, 1, 0]
]
# 对不存在的边赋予无限大权值的加权矩阵
inf = float('inf')
N = [
    [0, 1, 1, inf, 1],
    [1, 0, 1, inf, inf],
    [1, 1, 0, 1, 1],
    [inf, inf, 1, 0, 1],
    [inf, inf, 1, 1, 0]
]


# -*- 图  end -*-
class Vertex(object):
    """ 定义顶点"""

    def __init__(self, key):
        self.ID = key
        self.connectedTo = {}

    def addNeighbor(self, nbr, weight=None):
        """添加邻接顶点"""
        self.connectedTo[nbr] = weight

    def getConnections(self):
        """获取其所有邻接顶点"""
        return self.connectedTo.keys()  # 结合下文，这里keys 都是对象来的

    def getID(self):
        """获取其ID"""
        return self.ID

    def getWeight(self, nbr):
        """获取与其邻接的邻居之间的权重值"""
        return self.connectedTo[nbr]


class Graph(object):
    """定义一个图"""

    def __init__(self):
        self.vertexList = {}  # 保存图中的每一个顶点对象(包括对象之间的关系)
        self.vertexNum = 0  # 记录顶点数目

    def addVertex(self, key):
        """创建孤儿顶点对象并加到图中"""
        self.vertexNum += 1
        newVertex = Vertex(key)
        self.vertexList[key] = newVertex
        return newVertex

    def addEdge(self, vertex1, vertex2, weight):
        """连接两个顶点：vertex1->vertex2"""
        if vertex1 not in self.vertexList:
            self.addVertex(vertex1)
        if vertex2 not in self.vertexList:
            self.addVertex(vertex2)
        self.vertexList[vertex1].addNeighbor(self.vertexList[vertex2], weight)

    def getVertex(self, key):
        """获取顶点对象"""
        if key in self.vertexList:
            return self.vertexList[key]
        else:
            return None

    def getVertices(self):
        """获取所有顶点的名称"""
        return self.vertexList.keys()

    def __iter__(self):
        """把这个类设置为可迭代"""
        return iter(self.vertexList.values())


# 深度优先搜索实现步骤：
# （1）访问初始顶点 v 并标记顶点v已访问。
# （2）查找顶点 v 的第一个邻接顶点w。
# （3）若顶点v 的邻接顶点w存在，则继续执行；否则回溯到v，再找v的另外一个未访问过的邻接点。
# （4）若顶点w尚未被访问，则访问顶点w 并标记顶点w为已访问。
# （5）继续查找顶点w 的下一个邻接顶点wi，如果v 取值wi转到步骤（3）。直到连通图中所有顶点全部访问过为止。

    dfsVisited = []   # 记录被访问过的顶点,也就是深度优先搜索的路径

    def dfs(self, root):
        """深度优先搜索"""
        # 获取该顶点的所有邻接顶点，对其进行深度优先遍历
        connections = self.vertexList[root].getConnections()
        if root not in self.dfsVisited:
            self.dfsVisited.append(root)
            # print(root, end=' ')
            for neighbor in connections:
                self.dfs(neighbor.getID())
        return self.dfsVisited

    bfsVisited = []  # 记录被访问过的顶点,也就是广度优先搜索的路径

    def bfs(self, root):
        """ 广度优先搜索"""
        queue = []  # 队列，先进先出，
        queue.append(root)
        self.bfsVisited.append(root)
        while len(queue):  # 当队列里还有元素的时候，说明还有顶点未被访问
            vertex = queue.pop(0)  # 把先进的元素提取出来先处理
            for neighbor in self.vertexList[vertex].getConnections():
                if neighbor.getID() not in self.bfsVisited:
                    self.bfsVisited.append(neighbor.getID())
                    queue.append(neighbor.getID())  # 后进的元素
        return self.bfsVisited


if __name__ == '__main__':
    print("\n图：")
    graph = Graph()
    for vertex in range(6):
        graph.addVertex(vertex)
    graph.addEdge(0, 1, 5)
    graph.addEdge(0, 5, 2)
    graph.addEdge(1, 2, 4)
    graph.addEdge(2, 3, 9)
    graph.addEdge(3, 4, 7)
    graph.addEdge(3, 5, 3)
    graph.addEdge(4, 0, 1)
    graph.addEdge(5, 4, 8)
    graph.addEdge(5, 2, 1)
    print(graph.vertexList)  # 顶点
    # 打印图
    for vertex in graph:
        for neighbor in vertex.getConnections():
            print("( %s -> %s weight: %d)" %
                  (vertex.getID(), neighbor.getID(), vertex.getWeight(neighbor)))
    print(graph.dfs(3))
    print(graph.bfs(3))


# -*- 二叉树 begin -*-
# 前序遍历：根结点->左子树->右子树
# 中序遍历：左子树->根结点->右子树
# 后序遍历：左子树->右子树->根结点


class Node(object):
    """节点类"""

    def __init__(self, value=None, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right


class Tree(object):
    """定义二叉树类"""

    def __init__(self):
        self.root = Node()
        self.nodeList = []  # 用以存放相对的父节点，用以开辟其子节点

    def add(self, value):
        """添加节点"""
        node = Node(value)
        if self.root.value == None:  # 判断树是否是空的
            self.root = node
            self.nodeList.append(self.root)
        else:
            parentNode = self.nodeList[0]  # 给nodeList里面相对的父节点添加其子节点
            if parentNode.left == None:
                parentNode.left = node
                self.nodeList.append(parentNode.left)
            else:
                parentNode.right = node
                self.nodeList.append(parentNode.right)
                # 此时parentNode 已有两个节点，所以对它的构造完成，移除它
                self.nodeList.pop(0)

    def frontSearch(self, root):
        """递归前序遍历"""
        if root == None:
            return False
        print(root.value, end=' ')
        self.frontSearch(root.left)
        self.frontSearch(root.right)

    def midSearch(self, root):
        """递归中序遍历"""
        if root == None:
            return False
        self.midSearch(root.left)
        print(root.value, end=' '),
        self.midSearch(root.right)

    def backSearch(self, root):
        """递归后序遍历"""
        if root == None:
            return False
        self.backSearch(root.left)
        self.backSearch(root.right)
        print(root.value, end=' ')

    def frontStack(self, root):
        """利用堆栈前序遍历"""
        if root == None:
            return False
        stack = []
        node = root
        while node or stack:
            while node:  # 寻找左子树，压入栈内
                print(node.value, end=' ')
                stack.append(node)
                node = node.left
            node = stack.pop()
            node = node.right  # 开始寻找右子树

    def midStack(self, root):
        """ 利用堆栈中序遍历"""
        if root == None:
            return False
        stack = []
        node = root
        while node or stack:
            while node:  # 从根结点开始，寻找左子树，把它压入栈中
                stack.append(node)
                node = node.left
            node = stack.pop()  # while 结束代表前一个节点没有了左子树
            print(node.value, end=' ')
            node = node.right  # 然后开始寻找右子树

    def backStack(self, root):
        """利用堆栈后序遍历"""
        if root is None:
            return False
        stack1 = []
        stack2 = []
        stack1.append(root)
        while stack1:   # 找出后序遍历的逆序，存放在 stack2中
            node = stack1.pop()
            if node.left:
                stack1.append(node.left)
            if node.right:
                stack1.append(node.right)
            stack2.append(node)
        while stack2:  # 将 stack2中的元素出栈，即是后序遍历序列
            print(stack2.pop().value, end=' ')

    def levelSearch(self, root):
        """层序遍历"""
        if root is None:
            return False
        treeList = []
        treeList.append(root)
        while treeList:
            node = treeList.pop(0)  # 先进先出
            print(node.value, end=' ')
            if node.left:
                treeList.append(node.left)
            if node.right:
                treeList.append(node.right)


if __name__ == '__main__':
    print("\n树:")
    tree = Tree()
    for node in range(10):
        tree.add(node)
    tree.levelSearch(tree.root)
    print()
    tree.frontSearch(tree.root)
    print()
    tree.midSearch(tree.root)
    print()
    tree.backSearch(tree.root)
    print()
    tree.frontStack(tree.root)
    print()
    tree.midStack(tree.root)
    print()
    tree.backStack(tree.root)
    print()


# 二分查找(分治法)  时间复杂度为 O(logn)
def binarySearch(nums, item):
    first = 0
    last = len(nums)-1
    found = False
    while first <= last and not found:
        midPoint = (first+last)//2
        if nums[midPoint] == item:
            found = True
        else:
            if item < nums[midPoint]:
                last = midPoint-1
            else:
                first = midPoint+1
    return found

# 二分查找递归版本


def rec_binarySearch(nums, item):
    if len(nums) == 0:
        return False
    midPoint = len(nums)//2
    if nums[midPoint] == item:
        return True
    else:
        if item < nums[midPoint]:
            return rec_binarySearch(nums[:midPoint], item)
        else:
            return rec_binarySearch(nums[midPoint+1:], item)


# hash查找
# 构造哈希函数：分组求和法、平方取中法
# 解决哈希冲突：开放寻址、再哈希法、链地址法
class HashTable(object):
    """定义哈希表"""

    def __init__(self, size):
        """初始化大小、键值对"""
        # size 最好为素数
        self.size = size
        self.keys = [None]*self.size
        self.values = [None]*self.size

    def hashFunction(self, key):
        """哈希函数"""
        return key % self.size

    def reHash(self, oldHash):
        return (oldHash+1) % self.size

    def add(self, key, value):
        """添加数据"""
        hashValue = self.hashFunction(key)
        # 如果为空，那就直接把键值对加进去
        if self.keys[hashValue] == None:
            self.keys[hashValue] = key
            self.values[hashValue] = value
        # 如果不为，又分为两种情况
        else:
            # 如果key 已存在，那就替换掉
            if self.keys[hashValue] == key:
                self.values[hashValue] = value
            # 说明位置已被占用，继续哈希寻找空的位置
            else:
                rehashValue = self.reHash(hashValue)
                # 要么找到空的位置，要么找到存在的 key替换掉
                while self.keys[rehashValue] != None and self.keys[rehashValue] != key:
                    rehashValue = self.reHash(rehashValue)
                if self.keys[rehashValue] == None:
                    self.keys[rehashValue] = key
                    self.values[rehashValue] = value
                else:
                    self.keys[rehashValue] = value

    def get(self, key):
        """获取元素"""
        startIndex = self.hashFunction(key)

        data = None   # 想寻找的值可能不存在
        found = False
        stop = False
        position = startIndex
        # 如果位置为空，说明还没存过数据进来，就不需要继续寻找
        while self.keys[position] != None and not found and not stop:
            if self.keys[position] == key:
                found = True
                data = self.values[position]
            else:
                position = self.reHash(position)
                if position == startIndex:
                    stop = True
        return data

    def __getitem__(self, key):
        return self.get(key)

    def __setitem__(self, key, value):
        self.add(key, value)


# 冒泡排序  每次比较都有可能交换数据  时间复杂度O(n^2)
# 1.比较相邻的元素。如果第一个比第二个大，就交换他们两个。
# 2.对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
# 3.针对所有的元素重复以上的步骤，除了最后一个。
# 4.持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
# 稳定排序
def bubbleSort(nums):
    """冒泡排序"""
    # 每次比较之后剩下的比较数都会减一，因为每次比较都会有一个数已经冒泡到了该在的位置
    for passNum in range(len(nums)-1, 0, -1):
        # 每次第一个数都需要和其他没冒泡过的数相比较
        for i in range(passNum):
            if nums[i] > nums[i+1]:
                nums[i], nums[i+1] = nums[i+1], nums[i]


def shortBubbleShort(nums):
    """短冒泡排序"""
    exchange = True
    passNum = len(nums)-1
    while passNum > 0 and exchange:
        # 如果遍历期间不再交换位置，说明整个列表已经有序了，可以停止冒泡排序了
        exchange = False
        for i in range(passNum):
            if nums[i] > nums[i+1]:
                exchange = True
                nums[i], nums[i+1] = nums[i+1], nums[i]
        passNum = passNum-1


# 选择排序 每次遍历只做一次交换  时间复杂度O(n^2)
# 每次遍历找到为排序序列中最大的，然后把它放在正确的位置
# 不稳定排序
def seclectionSort(nums):
    """选择排序,改进了冒泡排序"""
    for fillSlot in range(len(nums)-1, 0, -1):
        positionOfMax = 0  # 每次都从第一次位置开始比较
        for location in range(1, fillSlot+1):
            if nums[location] > nums[positionOfMax]:  # 找出目前最大的那个数
                positionOfMax = location  # 然后把它的位置记录下来，用以和其他数比较
        # 每次遍历后，positionOfMax所在的数肯定是未排序中最大的
        nums[positionOfMax], nums[fillSlot] = nums[fillSlot], nums[positionOfMax]


# 插入排序 时间复杂度O(n^2)
# 和现有的有序序列比较，插入其中
# 稳定排序
def insertSort(nums):
    """插入排序"""
    for index in range(1, len(nums)):
        currentValue = nums[index]
        position = index
        while position >= 1 and nums[position-1] > currentValue:
            nums[position] = nums[position-1]
            position -= 1
        nums[position] = currentValue


# 希尔排序 时间复杂度在O(n)和O(n^2)之间
# 分解成多个较小的子列表来改进插入排序
# 不稳定排序
def gapInsertionSort(nums, start, gap):
    for i in range(start+gap, len(nums), gap):
        currentValue = nums[i]
        position = i
        while position >= gap and nums[position-gap] > currentValue:
            nums[position] = nums[position-gap]
            position -= gap
        nums[position] = currentValue


def shellSort(nums):
    gap = len(nums)//2  # gap其实也就是分成的子列表的个数
    while gap > 0:
        # 对每个子列表都进行插入排序
        for startPosition in range(gap):
            gapInsertionSort(nums, startPosition, gap)
        gap = gap//2


# 归并排序 时间复杂度 O(nlogn)
# 分而治之，先递归拆分列表，然后把两个有序的子列表合并
# 稳定排序
def mergeSort(nums):
    """递归拆分列表"""
    if len(nums) <= 1:
        return nums
    mid = len(nums) // 2
    left = mergeSort(nums[:mid])
    right = mergeSort(nums[mid:])
    return merge(left, right)


def merge(left, right):
    """合并排序"""
    result = []  # 用以存储新的排好序的列表
    i = 0  # left 的下标
    j = 0  # right 的下标
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    # 比较到最后，两个列表中肯定是一个列表已取完元素，另一个列表只剩下一个元素
    # 当切片索引超过列表长度时，切片为空列表
    result += left[i:]
    result += right[j:]
    return result


# 快速排序  最优时间复杂度 O(nlogn) 最坏时间复杂度O(n^2)
# 先从待排序的数组中找一个基准值，然后把原来的数组分成两部分：小于基准值的左子数组和大于基准值的右子数组，
# 然后对这个子数组再递归重复以上过程，直到最后的两个子数组的所有书都分别有序，
# 最后返回“左子数组+基准值+右子数组”，即是最终排序好的数组。
# 排序是不稳定的
def quickSort(nums):
    """快速排序，这个是占用了格外的存储空间来存储左右子数组"""
    if len(nums)<=1:
        return nums
    left = []
    right = []
    base = nums.pop(0)  # 不可以用base = nums[0]，原因是这样做的话 base 值仍在nums数组中，base会不断在子数组中，陷入死循环，无法满足递归出口条件
    # 对原数组进行划分
    for num in nums:
        if num < base:
            left.append(num)
        else:
            right.append(num)
    return quickSort(left) + [base] + quickSort(right)

def quickSort(nums):
    """快速排序，原地操作数组"""
    quickSortHelper(nums, 0, len(nums) - 1)
def quickSortHelper(nums, first, last):
    if first<last:
        splitPoint = partition(nums, first, last)
        quickSortHelper(nums, first, splitPoint - 1)
        quickSortHelper(nums, splitPoint + 1, last)
def partition(nums,first,last):
    """分区操作，把数组分成左边都比基准值小，右边都比基准值大"""
    base = nums[first]
    left = first + 1  # base 不要和自身比较
    right = last

    done = False
    while not done:
        while left <= right and nums[left] <= base:
            # 在左边找到一个比基准值大的值
            left += 1
        while left <= right and nums[right] >= base:
            # 在右边找到一个比基准值小的值
            right += 1
        if right<left:
            done = True
        else:
            # 然后交换位置
            nums[left], nums[right] = nums[right], nums[left]

    # 当循环结束，此时应该把基准值放到拆分点，此时基准值左边的值都比右边的值要小了，分区完成
    nums[right], base = base, nums[right]

    return right    # 返回此次基准值的位置，作为下一次分区的分割点




# 桶排序
# 将数组分到有限数量的桶子里。每个桶子再个别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排序）


# 基数排序
# 先对比数组中每个数的低位，分到不同的"桶子"里，再把它们重新串接起来，然后继续比较高一位，重复步骤，最后把它们
# 串接起来就是有序的序列了


# 堆排序
# 将待排序序列构造成一个大顶堆，此时，整个序列的最大值就是堆顶的根节点。将其与末尾元素进行交换，
# 此时末尾就为最大值。然后将剩余n-1个元素重新构造成一个堆，这样会得到n个元素的次小值。如此反复执行，便能得到一个有序序列了
def adjust_heap(lists, i, size):
    lchild = 2 * i + 1
    rchild = 2 * i + 2
    max = i
    if i < size / 2:
        if lchild < size and lists[lchild] > lists[max]:
            max = lchild
        if rchild < size and lists[rchild] > lists[max]:
            max = rchild
        if max != i:
            lists[max], lists[i] = lists[i], lists[max]
            adjust_heap(lists, max, size)


def build_heap(lists, size):
    for i in range(0, (size / 2))[::-1]:
        adjust_heap(lists, i, size)


def heap_sort(lists):
    size = len(lists)
    build_heap(lists, size)
    for i in range(0, size)[::-1]:
        lists[0], lists[i] = lists[i], lists[0]
        adjust_heap(lists, 0, i)
