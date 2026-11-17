/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool issamevalue(vector<vector<int>> &grid,int x1,int y1,int n)
    {
        for(int i=x1; i<x1+n; i++)
        {
            for(int j=y1; j<y1+n; j++)
            {
                if(grid[x1][y1]!= grid[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    Node* solve(vector<vector<int>> &grid,int x1,int y1,int n)
    {
        if(issamevalue(grid,x1,y1,n))
        {
            return new Node(grid[x1][y1],true);
        }
        else
        {
            Node* root = new Node(false,false);
            root->topLeft= solve(grid,x1,y1,n/2);
            root->topRight= solve(grid,x1,y1+n/2,n/2);
            root->bottomLeft= solve(grid,x1+n/2,y1,n/2);
            root->bottomRight= solve(grid,x1+n/2,y1+n/2,n/2);
            return root;
        }
    }
    Node* construct(vector<vector<int>>& grid) 
    {
        return solve(grid,0,0,grid.size());
    }
};