class Solution {
public:
    struct TrieNode
    {
        TrieNode* children[26];
        string word;

        TrieNode()
        {
            word = "";
            for(int i=0; i<26; i++)
            {
                children[i] = NULL;
            }
        }
    };

    TrieNode *buildTrie(vector<string>& words)
    {
        TrieNode* root = new TrieNode();

        for(int i=0; i<words.size(); i++)
        {
            string word = words[i];
            TrieNode* curr = root;

            for(int j=0; j<word.length(); j++)
            {
                int index = word[j] - 'a';

                if(curr->children[index] == NULL)
                {
                    curr->children[index] = new TrieNode();
                }
                curr = curr->children[index];
            }
            curr->word = word;
        }
        return root;
    }

    void dfs(vector<vector<char>> &board,int i,int j,TrieNode* p,vector<string> &result)
    {
        char c = board[i][j];

        if(c == '#' || !p->children[c-'a']) return;

        p = p->children[c-'a'];

        if(p->word.size() > 0)
        {
            result.push_back(p->word);
            p->word = "";
        }

        board[i][j] = '#';
        
        if(i > 0) dfs(board,i-1,j,p,result);
        if(j > 0) dfs(board,i,j-1,p,result);
        if(i< board.size()-1) dfs(board,i+1,j,p,result);
        if(j < board[0].size()-1) dfs(board,i,j+1,p,result);

        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        TrieNode* root = buildTrie(words);
        vector<string> result;

        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                dfs(board,i,j,root,result);
            }
        }
        return result;
    }
};
