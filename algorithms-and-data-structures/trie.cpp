#include <unordered_map>
#include <iostream>
#include <memory>
#include <array>
using namespace std;

class trie
{
private:
    struct node
    {
        node() : words(0), prefixes(0)
        { }

        int words;
        int prefixes;

        std::unordered_map<char, std::unique_ptr<node>> edges;
    };


    void addWord(node &e, const std::string &s, int i)
    {
        if(i == (int)s.size())
        {
            e.words++;
            return;
        }
        e.prefixes++;
        if(e.edges[s[i]] == nullptr)
            e.edges[s[i]] = std::unique_ptr<node>(new node());

        addWord(*e.edges[s[i]], s, i+1);
    }

    int countWords(node &e, const std::string &s, int i)
    {
        if(i == (int)s.size())
            return e.words;

        if(e.edges[s[i]] == nullptr)
            return 0;

        return countWords(*e.edges[s[i]], s, i+1);
    }

    int countPrefixes(node &e, const std::string &s, int i)
    {
        if(i == (int)s.size())
            return e.prefixes;

        if(e.edges[s[i]] == nullptr)
            return 0;

        return countPrefixes(*e.edges[s[i]], s, i+1);
    }

    node root;

public:
    trie(){ };

    void addWord(const std::string &s)
    {
        addWord(root, s, 0);
    }

    int countWords(const std::string &s)
    {
        return countWords(root, s, 0);
    }

    int countPrefixes(const std::string &s)
    {
        return countPrefixes(root, s, 0);
    }
};

int main()
{
    trie t;
    t.addWord("");
    t.addWord("abc");
    t.addWord("abcd");
    t.addWord("cat");
    t.addWord("dog");
    t.addWord("doggy");
    t.addWord("dog");
    t.addWord("doggies");
    t.addWord("przemyslawisawesome");
    
    cout << t.countWords("dog") << endl;
    cout << t.countPrefixes("do") << endl;
}


