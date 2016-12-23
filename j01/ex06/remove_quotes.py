#remove_quotes = lambda tab: [isinstance(i, str) and i.replace('\"', '') or i for i in tab]
#remove_quotes = lambda tab: [isinstance(i, str) and (i.replace('\"', '') and i.replace('\`', '')) or i for i in tab]
#remove_quotes = lambda tab: [isinstance(i, str) and '"'.join(k.replace('"', '') and k.replace('`', '') for k in i) or i for i in tab]
#remove_quotes = lambda tab: [isinstance(i, str) and (''.join(' '.join(k.replace('"', '') and k.replace('\'', '`') for k in i)).replace('`', '')) or i for i in tab]

remove_quotes = lambda tab: [isinstance(i, str) and (''.join(' '.join(k.replace('"', '') and k.replace('\'', '`') for k in i)).replace('`', '')) or i for i in tab]
