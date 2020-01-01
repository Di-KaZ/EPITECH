#### Server / Client Before join a party ####

### TCP ###

# Register to server
CLIENT -> REGISTER [ip] [name]
SERVER -> OK / ERROR [msg]

# Refresh list of party the client should read until **END** keyword
CLIENT -> REFRESH
SERVER -> [party_name] [player_num] [status]
# status is used to know if a party is aleready playing

# Join a party
CLIENT -> JOIN [party_name]
SERVER -> OK / ERROR [msg]

# Create a party
CLIENT -> CREATE [party_name]
SERVER -> OK / ERROR [msg]

### Server / Client When in a party ###

# Leave a party
CLIENT -> LEAVE
SERVER -> OK / ERROR [msg]

# Ready the client, when in this state the client can't send any other command than **UNREADY**
CLIENT -> READY
SERVER -> OK / ERROR [msg]

# Unready the client
CLIENT -> UNREADY
SERVER -> OK / ERROR [msg]

# Start the game when all player in party are ready (Creator of the room) ip is the one of creator
CLIENT -> START
SERVER -> START [ip] / ERROR [msg]

# Change party Creator
SERVER -> PROMOTE [name]
CLIENT -> OK / ERROR [msg]

### In game ####

### UDP ###

# Here Server is the Creator of the game

# Send players Stats
SERVER -> PLAYER [name] [x] [y] [life]

# Damage a player
SERVER -> DAMAGE [name] [count]

# Heal a player
SERVER -> HEAL [name] [count]

# Send Monster Stats
SERVER -> ENEMY [id] [type] [x] [y] [life]

# Damage Monster
SERVER -> DENEMY [id] [type] [count]

# Heal Monster
SERVER -> HENEMY [id] [type] [count]