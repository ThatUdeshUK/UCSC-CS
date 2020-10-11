import sys
import nltk
import argparse
import codecs


def run(grammar_file, input_file):
    grammar = nltk.data.load('file:' + grammar_file)
    parser = nltk.RecursiveDescentParser(grammar)

    file_input = codecs.open(input_file, 'r', 'utf-8-sig')

    count = 1
    for sent in file_input:
        sent_split = sent.split()
        print("----- Sentence:", count, "-----")
        print(sent)
        count += 1

        parsed = False;
        for tree in parser.parse(sent_split):
            print(tree)

            if not parsed:
                parsed = True

        if parsed:
            print("\nParse Success\n")
        else:
            print("\nParse Failed\n")


def main(arguments):
    parser = argparse.ArgumentParser()

    parser.add_argument("-g", "--grammar", type=str, default="grammar.cfg")
    parser.add_argument("-i", "--input_file", type=str, default="input.txt")

    args = parser.parse_args(arguments)

    grammar = args.grammar
    input_file = args.input_file

    run(grammar, input_file)


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
