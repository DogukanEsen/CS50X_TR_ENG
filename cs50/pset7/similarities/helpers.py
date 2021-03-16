from nltk.tokenize import sent_tokenize
def lines(a, b):
    """Return lines in both a and b"""

    lines=[]

    
    for line in a.split("\n"):
        if line in b.split("\n"):
            if line!="":
                lines.append (line)
    return lines


def sentences(a, b):
    """Return sentences in both a and b"""

    sentences = []
    
    a = sent_tokenize(a, language='english')
    b = sent_tokenize(b, language='english')

    for sentence in a:
        if sentence in b:
            if sentence:
                if sentence != "" and sentence not in sentences:
                    sentences.append(sentence)
    return sentences
        
def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    substrings = []
    a = get(a, n)
    b = get(b, n)
    for a in a:
        for b in b:
            if a==b and a not in substrings:
                substrings.append(a)
    return substrings
    
def get(s, n):
    gt = []
    for i in range(len(s) - n + 1):
        gt.append(s[i:i + n])
    return gt