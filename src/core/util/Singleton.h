#ifndef SINGLETON_H
#define SINGLETON_H

template <class ActualClass>
class Singleton
{
    public:
        static ActualClass& GetInstance()
        {
            static ActualClass s;
            return s;
        }
        virtual ~Singleton(){};
    protected:
        Singleton(){}
    private:
        Singleton(Singleton const &);
        Singleton& operator=(Singleton const&);
};

#endif // SINGLETON_H
