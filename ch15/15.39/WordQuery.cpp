#include"WordQuery.h"

Query::Query(const string&word) :m_q(std::make_shared<WordQuery>(word)){}