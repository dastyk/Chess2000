#ifndef POS_H
#define POS_H


struct Pos
{
	int rank; //1-8
	int files; //a-h
	Pos() : rank(-1), files(-1)
	{

	}
	Pos(int r, int f) : rank(r), files(f)
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