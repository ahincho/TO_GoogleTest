
# ifndef LIST_H
# define LIST_H

/*
    List Abstract Data Type
        L : List
        E, F : Element
    Signatures
        new : --> LIST
        append : LIST x E --> LIST
        head : LIST -/-> ELEMENT (PARTIAL)
        tail : LIST -/-> LIST (PARTIAL)
        size : LIST --> INT
        isEmpty : LIST --> BOOL
        printList : LIST --> VOID
    Axioms
        size(new) == 0
        size(append(L, E)) > 0
        size(append(new, E)) == 1
        isEmpty(new) == True
        isEmpty(append(L, E)) == False
        head(new) == Error
        head(append(append(new, E), F)) == E
        head(append(new, E)) == E
        tail(new) == Error
        tail(append(L, E)) == L
*/

template <typename T>

class List
{
    public:
        // Para que sea virtual no olvidar = 0
        virtual void append(T) = 0;
        virtual T head() = 0;
        virtual T tail() = 0;
        virtual int size() = 0;
        virtual bool isEmpty() = 0;
        virtual void printList() = 0;
};

# endif
