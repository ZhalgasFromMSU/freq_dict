# freq_dict
Frequency dict

# Installation

```(bash)
git clone https://github.com/ZhalgasFromMSU/freq_dict.git
cd freq_dict
cmake -B build -S .
cd build
cmake --build .
ln -s $(pwd)/freq /usr/local/bin/freq
```

# Usage
```(bash)
freq input.txt output.txt
```

# Complexity
Time O(N * log(N)), where N is number of characters in input file
Space O(N)

# Possible improvements
Data can be processed online:
```(c++)

std::unordered_map<std::string, size_t> frequencies;

while (true) {
  std::string buffer;
  char c = getchar();
  while (std::isalpha(c)) {
    buffer += std::tolower(c);
    c = getchar();
  }
  auto [it, inserted] = frequencies.emplace(std::move(buffer), 0);
  if (!inserted) {
    *it += 1;
  }
}

```
