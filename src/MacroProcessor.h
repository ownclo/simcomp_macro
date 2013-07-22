#ifndef MACROPROCESSOR_H
#define MACROPROCESSOR_H

class MacroProcessor {
private:
    /* data */

public:
    MacroProcessor();

    virtual ~MacroProcessor() {}

    void run(
        const std::string infile,
        const std::string outfile);
};

#endif /* end of include guard: MACROPROCESSOR_H */
