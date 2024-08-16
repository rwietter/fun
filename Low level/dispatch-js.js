const hi = () => console.log('hi')
const bye = () => console.log('bye')

const dipatchTable = [
    hi,
    bye
]

const dispatch = (action) => {
    if (action > dipatchTable.length || action < 1) {
        console.log('not found')
        return
    }
    dipatchTable[action - 1]()
}

dispatch(2)
