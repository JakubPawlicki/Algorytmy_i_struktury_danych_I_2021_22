#include <iostream>

typedef int Telement;

typedef struct Node {
    Telement info;
    Node *left;
    Node *right;
};

typedef Node *PNode;

class BinaryTree {
protected:
    PNode T;
public:
    BinaryTree() {
        T = NULL;
    }

    ~BinaryTree() {
        MAKENULL(T);
    }

    PNode PARENT(PNode n) {
        if (n == ROOT())
            return NULL;
        else
            return PARENT1(n, T);
    }

    PNode PARENT1(PNode n, PNode t) {
        if (t->left == n || t->right == n)
            return t;
        if (t->left == NULL || t->right == NULL)
            return NULL;

        PNode tmp1, tmp2;

        tmp1 = PARENT1(n, t->left);
        tmp2 = PARENT1(n, t->right);

        if (tmp1 != NULL)
            return tmp1;
        else
            return tmp2;
    }

    PNode LEFT_CHILD(PNode n) {
        return n->left;
    }

    PNode RIGHT_CHILD(PNode n) {
        return n->right;
    }

    Telement GetLabel(PNode n) {
        if (n != NULL)
            return n->info;
    }

    PNode BuildTree1(int m) {
        if (m == 0)
            return NULL;
        int nl, np;
        Telement x;
        PNode tmp;
        int ml = m / 2;
        int mp = m - ml - 1;
        std::cout << "Podaj wartosc do wstawienia: " << std::endl;
        std::cin >> x;
        tmp = new Node;
        tmp->info = x;
        tmp->left = BuildTree1(ml);
        tmp->right = BuildTree1(mp);
        return tmp;
    }

    void BuildTree(int m) {
        T = BuildTree1(m);
    }

    PNode ROOT() {
        return T;
    }

    void MAKENULL(PNode p) {
        if (p != NULL) {
            if (p->left != NULL) MAKENULL(p->left);
            if (p->right != NULL) MAKENULL(p->right);
            delete p;
            p = NULL;
        }
    }

    void PreOrder(PNode t) {
        if (t != NULL) {
            std::cout << t->info;
            PreOrder(t->left);
            PreOrder(t->right);
        }
    }

    void InOrder(PNode t) {
        if (t != NULL) {
            InOrder(t->left);
            std::cout << t->info;
            InOrder(t->right);
        }
    }

    void PostOrder(PNode t) {
        if (t != NULL) {
            PostOrder(t->left);
            PostOrder(t->right);
            std::cout << t->info;
        }
    }
};

int main() {
    BinaryTree binaryTree;
    binaryTree.BuildTree(9);
    std::cout << binaryTree.GetLabel(binaryTree.ROOT()) << std::endl;
    std::cout << binaryTree.GetLabel(binaryTree.LEFT_CHILD(binaryTree.ROOT())) << std::endl;
    std::cout << binaryTree.GetLabel(binaryTree.RIGHT_CHILD(binaryTree.ROOT())) << std::endl;

    binaryTree.PreOrder(binaryTree.ROOT());
    std::cout << std::endl;
    binaryTree.InOrder(binaryTree.ROOT());
    std::cout << std::endl;
    binaryTree.PostOrder(binaryTree.ROOT());

    std::cout << "\n#################################" << std::endl;
    std::cout << std::endl;
    std::cout << binaryTree.GetLabel(binaryTree.PARENT(binaryTree.RIGHT_CHILD(binaryTree.ROOT()))) << std::endl;
    std::cout
            << binaryTree.GetLabel(binaryTree.PARENT(binaryTree.RIGHT_CHILD(binaryTree.LEFT_CHILD(binaryTree.ROOT()))))
            << std::endl;

    std::cout<< binaryTree.GetLabel(binaryTree.PARENT(binaryTree.RIGHT_CHILD(binaryTree.RIGHT_CHILD(binaryTree.ROOT()))));
}