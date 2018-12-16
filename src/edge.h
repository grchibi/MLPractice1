#ifndef _EDGE_H_
#define _EDGE_H_

#include <memory>
#include "node.h"

namespace ML
{

	class Edge
	{
	public:
		std::shared_ptr<Node> left_;
		std::shared_ptr<Node> right_;
		double weight_;

		Edge(void);
		~Edge() {}
	};

}

#endif	// _EDGE_H_
