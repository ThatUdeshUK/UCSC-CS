# -*- coding: utf-8 -*-
import nltk
import codecs

load_grammar = nltk.data.load('file:grammar.cfg')
file_input = codecs.open('input.txt', 'r', 'utf-8-sig')

for sent in file_input:
        sent_split = sent.split()
        rd_parser = nltk.RecursiveDescentParser(load_grammar)
        for tree_struc in rd_parser.parse(sent_split):
                s = unicode(tree_struc).encode('utf-8-sig')
                print s

#Exercise:
#Modify this code to display the unicode text properly and
#save the outputs to a file
