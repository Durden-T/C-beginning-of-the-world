class Trie
{
    Trie *children[26] = {nullptr};
    bool end = false;

  public:
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *Tmp = this;
        for (int i : word)
        {
            if (!Tmp->children[i - 'a'])
                Tmp->children[i - 'a'] = new Trie;
            Tmp = Tmp->children[i - 'a'];
        }
        Tmp->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie *Tmp = this;
        for (int i : word)
        {
            if (!Tmp)
                return false;
            Tmp = Tmp->children[i - 'a'];
        }
        return Tmp && Tmp->end;
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Trie *Tmp = this;
        for (int i : prefix)
        {
            if (!Tmp)
                return false;
            Tmp = Tmp->children[i - 'a'];
        }
        return Tmp;
    }
};

//递归
class TrieNode
{
  public:
    bool end = false;
    TrieNode *next[26] = {nullptr};

    void insert(string word, int index)
    {
        if (word.size() == index)
        {
            end = true;
            return;
        }

        int c = word[index] - 'a';
        if (!next[c])
            next[c] = new TrieNode;

        next[c]->insert(word, index + 1);
    }

    bool find(string word, int index)
    {
        if (index == word.size())
            return end;
        if (word[index] == '.')
        {
            for (int i = 0; i < 26; i++)
                if (next[i] && next[i]->find(word, index + 1))
                    return true;
            return false;
        }
        return next[word[index] - 'a'] ? next[word[index] - 'a']->find(word, index + 1) : false;
    }
};
