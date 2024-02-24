/* https://faculty.cs.niu.edu/~mcmahon/CS241/Notes/Data_Structures/binary_tree_traversals.html */

#include <iostream>
#include <queue>
#include <stack>

struct Node{
    char _id;
    Node* _left;
    Node* _right;
    Node(char id) : _id{id}, _left{nullptr}, _right{nullptr}{}
    Node(char id, Node* left, Node* right) : _id{id}, _left{left}, _right{right}{}
};
Node E{'E'};
Node M{'M'};
Node P{'P'};
Node N{'N'};
Node H{'H'};

Node X{'X',&E,&M};
Node S{'S'};
Node T{'T', &P, &N};
Node C{'C', &H, nullptr};

Node B{'B',&X,&S};
Node W{'W',&T,&C};

Node A{'A',&B,&W};

enum class Direction{LeftToright, RightToLeft};

/* In a preorder traversal of a binary tree, we "visit" a node and then traverse both of its subtrees. 
 * Usually, we traverse the node's left subtree first and then traverse the node's right subtree.
 * Note that the left-to-right preorder traversal and the right-to-left preorder traversal are not mirror images of each other
 */
void RecursivePreorderTraversal(Node* node, Direction dir) {
    if(node != nullptr) {
        std::cout << node->_id << " ";
        switch(dir) {
            case Direction::LeftToright :
                RecursivePreorderTraversal(node->_left, dir);
                RecursivePreorderTraversal(node->_right, dir);
                break;
            case Direction::RightToLeft :
                RecursivePreorderTraversal(node->_right, dir);
                RecursivePreorderTraversal(node->_left, dir);
                break;
        }
    }
}
void IterativePreorderTraversal(Node* node, Direction dir) {
    std::stack<Node*> stack{};
    while(node != nullptr || !stack.empty()){
        while(node != nullptr) {
            std::cout << node->_id << " ";
            stack.push(node);
            node = (dir == Direction::LeftToright) ? node->_left : node ->_right;
        }
        node = stack.top();
        stack.pop();
        // try the other leg
        node = (dir == Direction::LeftToright) ? node->_right: node->_left;
    }
}

/* In an inorder traversal of a binary tree, we traverse one subtree of a node, 
 * then "visit" the node, and then traverse its other subtree. Usually, 
 * we traverse the node's left subtree first and then traverse the node's right subtree
 * Note that the left-to-right inorder traversal and the right-to-left inorder traversal are mirror images of each other
 */
void RecursiveInorderTraversal(Node* node, Direction dir){
    if(node != nullptr) {
        auto next = (dir == Direction::LeftToright) ? node->_left : node ->_right;
        RecursiveInorderTraversal(next, dir);
        std::cout << node->_id << " ";
        next = (dir == Direction::LeftToright) ? node->_right: node->_left;
        RecursiveInorderTraversal(next, dir);
    }
}
void IterativeInorderTraversal(Node* node, Direction dir) {
    std::stack<Node*> stack{};
    while(node != nullptr || !stack.empty()){
        while(node != nullptr) {
            stack.push(node);
            node = (dir == Direction::LeftToright) ? node->_left : node ->_right;
        }
        node = stack.top();
        stack.pop();
        std::cout << node->_id << " ";
        // try the other leg
        node = (dir == Direction::LeftToright) ? node->_right: node->_left;
    }
}

/* In a postorder traversal of a binary tree, we traverse both subtrees of a node,
 * then "visit" the node. Usually we traverse the node's left subtree first and then
 * traverse the node's right subtree.
 * Note that the left-to-right postorder traversal and the right-to-left postorder traversal
 * are not mirror images of each other.
 * However, we can now see that the left-to-right postorder traversal is a mirror image of the
 * right-to-left preorder traversal,
 * while the right-to-left postorder traversal is a mirror image of the
 * left-to-right preorder traversal.
*/
void RecursivePostorderTraversal(Node* node, Direction dir) {
    if(node != nullptr) {
        auto next = (dir == Direction::LeftToright) ? node->_left : node ->_right;
        RecursivePostorderTraversal(next, dir);
        next = (dir == Direction::LeftToright) ? node->_right: node->_left;
        RecursivePostorderTraversal(next, dir);
        std::cout << node->_id << " ";
    }
}
void IterativePostorderTraversal(Node* node, Direction dir) {
    Node* root = node;
    std::stack<Node*> stack{};
    Node *last_visited = nullptr;
    while(node != nullptr && (last_visited != root)){
        while(node != nullptr && (node != last_visited)) {
            stack.push(node);
            node = (dir == Direction::LeftToright) ? node->_left : node ->_right;
        }
        node = stack.top();
        stack.pop();
        switch(dir) {
            case Direction::LeftToright :
                if((node->_right == nullptr) || (node->_right == last_visited)) {
                    std::cout << node->_id << " " << std::flush;
                    last_visited = node;
                } else {
                    stack.push(node);
                    node = node->_right;
                }
            break;
            case Direction::RightToLeft :
                if((node->_left == nullptr) || (node->_left == last_visited)) {
                    std::cout << node->_id << " " << std::flush;
                    last_visited = node;
                } else {
                    stack.push(node);
                    node = node->_left;
                }
            break;
        }
    }
}

void RecursiveLevelorderTraversal(Node* node, Direction dir) {
}

void IterativeLevelorderTraversal(Node* node, Direction dir) {
}

int main() {
    std::cout << "RecursivePreorderTraversal LeftToright\n";
    RecursivePreorderTraversal(&A, Direction::LeftToright);
    std::cout << "\n";
    std::cout << "RecursivePreorderTraversal RightToLeft\n";
    RecursivePreorderTraversal(&A, Direction::RightToLeft);
    std::cout << "\n";

    std::cout << "IterativePreorderTraversal LeftToright\n";
    IterativePreorderTraversal(&A, Direction::LeftToright);
    std::cout << "\n";
    std::cout << "IterativePreorderTraversal RightToLeft\n";
    IterativePreorderTraversal(&A, Direction::RightToLeft);
    std::cout << "\n";

    std::cout << "RecursiveInorderTraversal LeftToright\n";
    RecursiveInorderTraversal(&A, Direction::LeftToright);
    std::cout << "\n";
    std::cout << "RecursiveInorderTraversal RightToLeft\n";
    RecursiveInorderTraversal(&A, Direction::RightToLeft);
    std::cout << "\n";

    std::cout << "IterativeInorderTraversal LeftToright\n";
    IterativeInorderTraversal(&A, Direction::LeftToright);
    std::cout << "\n";
    std::cout << "IterativeInorderTraversal RightToLeft\n";
    IterativeInorderTraversal(&A, Direction::RightToLeft);
    std::cout << "\n";

    std::cout << "RecursivePostorderTraversal LeftToright\n";
    RecursivePostorderTraversal(&A, Direction::LeftToright);
    std::cout << "\n";
    std::cout << "RecursivePostorderTraversal RightToLeft\n";
    RecursivePostorderTraversal(&A, Direction::RightToLeft);
    std::cout << "\n";

    std::cout << "IterativePostorderTraversal LeftToright\n";
    IterativePostorderTraversal(&A, Direction::LeftToright);
    std::cout << "\n";
    std::cout << "IterativePostorderTraversal RightToLeft\n";
    IterativePostorderTraversal(&A, Direction::RightToLeft);
    std::cout << "\n";


    std::cout << "RecursiveLevelorderTraversal LeftToright\n";
    RecursiveLevelorderTraversal(&A, Direction::LeftToright);
    std::cout << "\n";
    std::cout << "RecursiveLevelorderTraversal RightToLeft\n";
    RecursiveLevelorderTraversal(&A, Direction::RightToLeft);
    std::cout << "\n";

    std::cout << "IterativeLevelorderTraversal LeftToright\n";
    IterativeLevelorderTraversal(&A, Direction::LeftToright);
    std::cout << "\n";
    std::cout << "IterativeLevelorderTraversal RightToLeft\n";
    IterativeLevelorderTraversal(&A, Direction::RightToLeft);
    std::cout << "\n";
}