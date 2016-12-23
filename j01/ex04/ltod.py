#ltod = lambda tab: {dict(tab[i], i + 1) for i in tab}
#ltod = lambda tab: dict((tab.pop(tab[i + 1]), tab.count(i)) for i in set(tab))
#ltod = lambda tab: dict((tmp, tab.count(i)) for i, tmp in enumerate(tab))
#ltod = lambda tab: dict((i, tab.pop(tmp + 1)) for i, tmp in enumerate(tab))
#ltod = lambda tab: dict((i, tab.count(i)) for i in tab)

ltod = lambda tab: dict((tmp, tab.pop(i + 1)) for i, tmp in enumerate(tab))
