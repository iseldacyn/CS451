#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <utility>
#include <queue>
#include <stack>
using namespace std;

/* State class for PCP Problem */
class State
{
	public: 

	// Data: list of dominoes, current top string, current bottom string
	vector<pair<string,string>> dominoes;
	string top_string;
	string bottom_string;	

	// Constructor for initial state
	State( vector<pair<string,string>> dom )
	{
		dominoes = dom;
		top_string = dom.front().first;
		bottom_string = dom.front().second;
	}
	// Constructor for next state
	State( vector<pair<string,string>> dom, string t, string b )
	{
		dominoes = dom;
		top_string = t;
		bottom_string = b;
	}
	State() { dominoes = {}; top_string = ""; bottom_string = ""; }

	// Check if top and bottom string are equal
	bool goal_test()
	{
		if ( top_string == bottom_string )
			return 1;
		else
			return 0;
	}

	// Print function
	void print()
	{
		cout << "[ Top String: " << top_string << " === Bottom String: " << bottom_string << " ]" << endl;
	}

	// Find successors of current state
	vector<pair<State,string>> find_successors()
	{
		vector<pair<State,string>> successors;
		for ( int i = 0; i < dominoes.size(); i++ )
		{
			// Gets new top and bottom string from next domino
			string next_top = this->top_string + dominoes[i].first;
			string next_bottom = this->bottom_string + dominoes[i].second;

			// Gets new state and provides action text for the Node
			State s = State( dominoes, next_top, next_bottom );
			string action = "Concatenate domino " + to_string(i+1);

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
	cout << "***** PCP Implementation *****" << endl;

	// Read in number of dominoes for the problem
	int num_domino;
	cout << "How many dominoes? ";
	cin >> num_domino;
	if ( num_domino < 1 )
	{
		cout << "There must be at least one domino!" << endl;
		exit(1);
	}

	// Read in all domino strings
	vector<pair<string,string>> dominoes;
	for ( int i = 0; i < num_domino; i++ )
	{
		pair<string,string> tmp;
		// Ensures that first domino given will be the one to start the problem
		if ( i == 0 )
			cout << "Top string of initial (starting) domino: ";
		else
			cout << "Top string of domino " << i+1 << ": ";
		cin >> tmp.first;
		if ( i == 0 )
			cout << "Bottom string of initial (starting) domino: ";
		else
			cout << "Bottom string of domino " << i+1 << ": ";
		cin >> tmp.second;
		dominoes.push_back( tmp );
	}

	// Create initial state for domino
	State initial_state = State( dominoes );

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


