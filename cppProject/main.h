extern inline void do_something (void);

asm("");
__asm__("");

namespace noSpace
{
class Main
{
public:
  void
  func ()
  {
    __asm__("");
    int src = 1;
    int dst;
    asm("mov %1, %0\n\t"
        "add $1, %0"
        : "=r"(dst)
        : "r"(src));
  }
};
}

#define VariadicMacros(format, ...)                                            \
  {                                                                            \
    std::cout << format << __LINE__ << #__VA_ARGS__ << std::endl;              \
  }
#define LostAndFoundBaggageClaim(format, ...)                                  \
  {                                                                            \
    std::cout << format << __DATE__ << '#' << __TIME__ << '#' << __cplusplus   \
              << '#' << __GNUC__ << '#' << __GNUC_MINOR__ << '#'               \
              << __GNUC_PATCHLEVEL__ << '#' << __VERSION__ << std::endl;       \
  }
#define TemplateFutureContract { // extern inline: export// }
#define documentationConfract {  // This is a documentaion text // }
#define myMac ((3 - (2 + 4)) - (0 / (2 + 3))) * 3
