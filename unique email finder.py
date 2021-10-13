def numUniqueEmails(emails) -> int:
		s = [];
		for email in emails:
			sp = email.split("@");
			name = sp[0];
			domain = sp[1];

			ind = name.find('+');

			if(ind != -1):
				name = name[0:ind]

			name = ''.join(name.split('.'))

			newMail = name + '@' + domain;
			s.append(newMail);

		st = set(s);

		return len(st);


emails = input().split(' ')

print(numUniqueEmails(emails))
