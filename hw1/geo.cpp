#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <utility>
#include <queue>
#include <stack>
using namespace std;

/* State class for Geography Problem */
class State
{
	public:
	// Data: set of words to choose from, current order of words picked
	vector<string> wordset;
	vector<string> order;

	// Constructor for initial state
	State( vector<string> words )
	{
		wordset = words;
		order = {};
		order.push_back( wordset.front() );
		wordset.erase( wordset.begin() );
	}
	// Constructor for next state
	State( vector<string> available, vector<string> current, int i )
	{
		wordset = available;
		order = current;
		order.push_back( wordset[i] );
		wordset.erase( wordset.begin() + i );
	}
	State() { wordset = {}; order = {}; }

	// Checks if initial word set is empty (i.e. every word has been reached)
	bool goal_test()
	{
		if ( wordset.empty() )
			return 1;
		else
			return 0;
	}

	// Print function
	void print()
	{
		for ( int i = 0; i < order.size(); i++ )
			cout << order[i] << " ";
		cout << endl;
	}

	// Find successors of current state
	vector<pair<State,string>> find_successors()
	{
		vector<pair<State,string>> successors = {};
		for ( int i = 0; i < wordset.size(); i++ )
		{
			// If last letter in current order is not the same as first
			// letter in next word, continue
			if ( wordset[i].front() != order.back().back() )
				continue;

			// Create new state and give action text for Node
			State s = State( wordset, order, i );
			string action = "Continue with word " + wordset[i];

			// Adds new pair to list of successors
			pair<State,string> tmp;
			tmp.first = s;
			tmp.second = action;
			successors.push_back( tmp );
		}

		return successors;
	}
};

/* Node Class */
class Node
{
	public: 

	State current_state;

	Node *parent;
	string action;

	int num_active_successors;

	// Constructor for Node from initial state
	Node( State c )
	{
		current_state = c;
		parent = NULL;
		action = "Initial State";
		num_active_successors = 0;
	}
	// Constructor for successor nodes
	Node( pair<State,string> c, Node *p )
	{
		current_state = c.first;
		parent = p;
		action = c.second;
		num_active_successors = 0;
	}
	Node() { current_state = State(); parent = NULL; action = ""; num_active_successors = 0; }
	
	// Deconstructor for Node
	~Node()
	{
		if ( parent != NULL )
		{
			parent->num_active_successors--;
			if ( parent->num_active_successors == 0 )
				delete parent;
		}
	}

	// Prints solution of the problem
	void print_solution()
	{
		if ( parent == NULL )
		{
			cout << "Initial State: ";
			current_state.print();
		}
		else
		{
			parent->print_solution();
			cout << "Action: " << action << endl;
			cout << "State: ";
			current_state.print();
		}
	}
};

/* BFS Algorithm */
void bfs(State initial)
{
	// Add first node to the fringe
	queue<Node*> fringe;
	fringe.push( new Node( initial ) );

	// Perform while fringe still has nodes
	while ( !fringe.empty() )
	{
		// Pop front node from fringe and get state
		Node *np = fringe.front();
		fringe.pop();
		State s = np->current_state;

		// Check if state is a goal state
		if ( s.goal_test() )
		{
			cout << "Solution Found!" << endl;
			np->print_solution();
			return;
		}

		// Find successors of current state
		cout << "Current state is being expanded..." << endl;
		vector<pair<State,string>> s_ = s.find_successors();
		np->num_active_successors += s_.size();

		// Add nodes to the fringe from successsors
		for ( int i = 0; i < s_.size(); i++ )
		{
			Node *n_ = new Node( s_[i], np );
			fringe.push( n_ );
		}
		if ( s_.empty() )
			delete np;
	}
	cout << "No solution!" << endl;
	return;
}

/* DFS Algorithm */
void dfs(State initial)
{
	// Add first node to the fringe
	stack<Node*> fringe;
	fringe.push( new Node( initial ) );

	// Perform while fringe still has nodes
	while ( !fringe.empty() )
	{
		// Pop top node from fringe and get state
		Node *np = fringe.top();
		fringe.pop();
		State s = np->current_state;

		// Check if state is a goal state
		if ( s.goal_test() )
		{
			cout << "Solution Found!" << endl;
			np->print_solution();
			return;
		}

		// Find successors of current state
		cout << "Current state is being expanded..." << endl;
		vector<pair<State,string>> s_ = s.find_successors();
		np->num_active_successors += s_.size();

		// Add nodes to the fringe from successsors
		for ( int i = 0; i < s_.size(); i++ )
		{
			Node *n_ = new Node( s_[i], np );
			fringe.push( n_ );
		}
		if ( s_.empty() )
			delete np;
	}
	cout << "No solution!" << endl;
	return;
}

int main()
{
	cout << "***** Geography Implementation *****" << endl;

	// Get set of words for problem
	int num_words;
	cout << "How many words in the set? ";
	cin >> num_words;
	if ( num_words < 1 )
	{
		cout << "There must be at least one word in the set!" << endl;
		exit(1);
	}

	vector<string> words;
	for ( int i = 0; i < num_words; i++ )
	{
		string tmp;
		if ( i == 0 )
			cout << "Provide the starting word: ";
		else
			cout << "Prove word " << i+1 << ": ";
		cin >> tmp;
		words.push_back( tmp );
	}

	// Create initial state of words
	State initial_state = State( words );

	// Prompts which search method should be used
	string input;
	cout << "Would you like (b)fs or (d)fs? " << endl;
	cin >> input;
	if ( input == "b" || input == "B" || input == "bfs" )
		bfs( initial_state );
	else if ( input == "d" || input == "D" || input == "dfs" )
		dfs( initial_state );
	else
		cout << "Could not parse " << input << "!" << endl;

	return 0;
}


