
# 控制平衡
1. 更新平衡因子（新增在右，parent平衡因子++；新增在左，parent平衡因子--）
2. 更新后parent平衡因子是1/-1，说明parent插入之前平衡因子是0，说明
    左右子树高度相等，插入后高度变了，要继续往上更新
3. 更新后parent平衡因子是0，说明不用继续向上更新了
4. 更新后parent平衡因子是2/-2，说明parent插入前的平衡因子是1/-1，对parent所在的子树要进行旋转
