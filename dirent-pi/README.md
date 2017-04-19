# Coping with different alignments on different platforms 
I'm experimenting with how to safely modify xapian-core so it'll compile on a Raspberry Pi. It's used by various kiwix projects, including - indirectly in a library - my work on kiwix-apache. Here's a minimal extract of the code that doesn't currently compile. I've reflected all the relevant compiler warning flags in the Makefile (otherwise g++ compiles the code without error).

## The error I'm trying to address
```
main.cpp:8:57: error: cast from ‘char*’ to ‘dirent*’ increases required alignment of target type [-Werror=cast-align]
   dirent *d = reinterpret_cast<struct dirent*>(buf + pos);
```

## Compiling xapian-core
This is relevant for once we've resolved the cause of the warning

https://trac.xapian.org/browser/git/xapian-core/HACKING

## Here are some links I'm learning from:

http://en.cppreference.com/w/cpp/language/reinterpret_cast (includes a useful online compiler)

http://stackoverflow.com/questions/2741787/warning-cast-increases-required-alignment (the Q&A that I'm trying to understand first)

The following are all examples of how people addressed - in different ways - similar problems. Some fixes won't apply directly, but may provide insights into how we can best fix the issue given our experience and expertise.

- https://svn.apache.org/viewvc/qpid/trunk/qpid/cpp/src/qpid/broker/amqp/Outgoing.cpp?r1=1521433&r2=1521432&pathrev=1521433
- https://gcc.gnu.org/bugzilla/show_bug.cgi?id=43976
- https://github.com/Microsoft/cpprestsdk/issues/59
- https://bugs.webkit.org/attachment.cgi?id=64485&action=prettypatch
