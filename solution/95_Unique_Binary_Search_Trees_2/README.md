枚举的思路和Unique BST I的思路一样。

枚举数组中的每个数i，把它们当作root.

root的左子树由 1~i-1 这i-1的数构成;右子树由i+1~n这n-i-1个数构成.左右子树可以递归的构建.

设dp[n] 为保存 1~n 构成树的一个容器。递归的构造dp[n]的所有树，若根是i：
``` cpp
initial root

for(left : dp[i-1])
{
    for(right : dp[n - i - 1])
    {
        以right为根的树每个节点val都加上i
        root->left = left;
        root->right = right;
    }
}

dp[n].push_back(root);
```

虽然我们可以将dp[0]~dp[n-1]都保存下来，但是因为是树，且要用到多次，所以每次用都得拷贝一次。所以和每次递归去算时间复杂度应该是一样的，但是可以省去递归调用的时间开销。

###直接用trees[n-1]构造trees[n]

在DISCUSS中看到一种方法，直接用n-1的结果构造n的结果。

1.可以将前一个结果直接作为新节点的左子树:
``` cpp
newRoot->left = oldRoot;
```

2.将newRoot挂在oldRoot右子树上，oldRoot原本的右子树当作newRoot的左子树。
``` cpp
newRoot->left = oldRoot->right;
oldRoot-right = newRoot;
```

然后oldRoot = oldRoot->right, 再重复用上述式子构造，直至oldRoot为NULL。


这种方法很巧妙，但是仔细想想，还是要拷贝前面的结果，因为trees[n-1]是需要多次利用的。
不过计算trees[n]只需要利用trees[n-1]的结果，计算完trees[n]，trees[n-1]不再需要保存。当进行到最后一遍，可以直接将trees[n-1]的结果拿来用，不用再拷贝了。相比上面的方法，计算trees[n]，可以少拷贝一次trees[1]~trees[n-1]。