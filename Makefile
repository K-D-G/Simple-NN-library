commit:
	git add .
	git commit -m "$(m)"
	git push

sort_conflicts:
	git stash
	git pull

sort_commit:
	make sort_conflicts
	make commit m="$(m)"
