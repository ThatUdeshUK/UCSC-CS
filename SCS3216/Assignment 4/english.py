import sys
import argparse
import nltk

grammar_cfg = """
S -> NP VP
VP -> V NP | V NP PP
PP -> P NP
V -> "saw" | "ate" | "walked"
NP -> "John" | "Mary" | "Bob" | Det N | Det N PP 
Det -> "a" | "an" | "the" | "my"
N -> "man" | "dog" | "cat" | "telescope" | "park" 
P -> "in" | "on" | "by" | "with"
"""


def run():
    grammar = nltk.CFG.fromstring(grammar_cfg)
    parser = nltk.RecursiveDescentParser(grammar)

    text = "John ate a cat"

    for tree in parser.parse(text.split()):
        print(tree)

    #
    # while True:
    #     text = input("Enter string to parse?\n")
    #     for tree in parser.parse(text):
    #         print(tree)
    #
    #     print("--- Parse Successful ---")


def main(arguments):
    # parser = argparse.ArgumentParser()
    #
    # parser.add_argument("text", type=str)
    #
    # args = parser.parse_args(arguments)
    #
    # text = args.text

    run()


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
