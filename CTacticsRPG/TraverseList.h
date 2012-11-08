template<typename T>
class TraverseList {
	private:
		struct Data {
			T* m_data;
			Data* m_next;
		};

		Data* m_head;
	
	public:
		~TraverseList() {
			m_head -> m_data -> ~T();
			while ((m_head = m_head -> m_next) != NULL) {
				m_head -> m_data -> ~T();
			}
			delete[] m_head;
		}

		void insert(T a_type) {
			Data l_data;
			l_data.m_data = &a_type;
			l_data.m_next = &m_head;
			m_head = &l_data;
		}

		T* remove(T &a_type) {
			if (m_head -> m_next == NULL) {
				T* l_data = m_head -> m_data;;
				m_head = NULL;
				return l_data;
			}

			Data* l_current = m_head;
			Data* l_previous;

			while ((l_current = l_current -> m_next) != NULL) {
				if (l_current -> *m_data == a_type) {
					T* l_data = l_current -> m_data;
					l_previous -> m_next = l_current -> m_next;
					return l_data;				
				}
				l_previous = l_current;
			}
		}
};