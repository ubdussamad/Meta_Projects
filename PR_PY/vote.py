from datetime import datetime

try:
        from lib.decorate import read_only #Not very sure what does it do?
except:
        read_only = lambda x: 0


class Votable:
        """A Votable object is an object that people can cast votes on.
          The votes are recorded in self._votes.  Votable has no __init__ because
          it's purpose is to be inherited by other objects that we want to become votable.
          Those objects will have their own __init__s, and should include the line `self._votes = []` in their __init__."""


        def votes(self):
                """ Returns the list of Vote objects, in chronological order by their date. """
                return self._votes

        def add_vote(self, vote):
                """ Insert the new vote into the list of Vote objects, maintaining chronlogical order by date. """
                for old_vote in reversed(self.votes()):
                        if old_vote.date < vote.date:
                                # TODO: insert vote immediately after old_vote
                                self._votes.append(vote) #Done kinda
                                return
                # TODO: insert vote at very beginning
                self._votes = [vote] + self._votes #Done kinda

        def upvotes(self):
                """ Return the NUMBER of upvotes this Atom has. """
                upvote_list = [vote for vote in self.votes() if vote.is_up()]
                return len(upvote_list)

        def downvotes(self):
                downvote_list = [vote for vote in self.votes() if vote.is_down()]
                return len(downvote_list)

        def score(self):
                """ Calculate the Atom's score based on its votes. """
                score_list = [vote.parity() * vote.weight() for vote in self.votes()]
                return sum(score_list)


class Vote:
        """ A Vote object is a timestamp of when the vote was cast, and whether it was an upvote or a downvote. """


        def __init__(self, kind, date=None):
                self.kind = kind
                self.date = date

        @property
        def kind(self):
                return self._kind
        @kind.setter
        def kind(self, new_kind):
                if new_kind in {'up', 'down'}:
                        self._kind = new_kind
                else:
                        raise Exception('Bad Vote kind.')

        def is_up(self):
                return self.kind == 'up'

        def is_down(self):
                return not self.is_up()

        def parity(self):
                if self.is_up():
                        return 1
                else:
                        return -1

        @property
        def date(self):
                return self._date
        @date.setter
        @read_only
        def date(self, new_date):
                # convert JS dates to datetime objects?

                if isinstance(new_date, datetime): #if user can pass the utc based datetime object
                        self._date = new_date
                elif new_date == None:
                        self._date = datetime.utcnow() #if user can't pass the current utc time and wishes to datestamp the vote with current time..
                        #.. then he should pass a none to the setter (I am not sure that it's helpful or not)
                else:
                        raise Exception('Date is not of type datetime.')
        @staticmethod
        def weight_decay(x,weight_initial=1):  #Not a very good implimentation but thats what i could do by myself
                def decay(z):return (0.2)**z
                for i in range(1,x):weight_initial -= decay(i)
                return wti
        
        def weight(self):
                #We initialize a weight at 1
                # in the future, we want the weight to decrease as the date gets older
                now = datetime.utcnow()
                elapsed_time = now - self.date
                return weight_decay(int(elapsed_time.days)) #NOT sure how to convert time delta type to int





a = rarw_input("whatch ya thinkin??")
