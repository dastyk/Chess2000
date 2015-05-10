#ifndef POS_H
#define POS_H


struct Pos
{
	int files; //a-h
	int rank; //1-8
	Pos() : rank(-1), files(-1)
	{

	}
	Pos(int f, int r) : rank(r), files(f)
	{

	}
	inline bool operator==(const Pos& p)
	{
		if (rank == p.rank)
			if (files == p.files)
				return true;
		return false;
	}
};

#endif