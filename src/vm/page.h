#ifdef VM_PAGE_H
#define VM_PAGE_H

#include <hash.h>
#include <debug.h>
/*  2018.05.08 
 *  KimYoonseo
 *  EomSungha
 */
enum loc_type
{
  LOC_FS;   /* Filesys */
  LOC_SW;   /* Swap table */
  LOC_PT;   /* Page table */
}

/* Supplement page table entry */
struct spte
{
  struct hash_elem hash_elem;   /* Hash table element */
  void *addr;                   /* Virtual user address */
  struct file *file;            /* File */
  off_t ofs;                    /* Offset */
  uint32_t read_bytes;          /* Load_segment's read_bytes */
  uint32_t zero_bytes;          /* Load_segment's zero_bytes */    
  bool writable;                /* Writable */
  loc_type location;            /* Location */ 
};

void spt_init (struct hash *spt);
struct spte *spte_lookup (const void *addr);
bool fs_load (struct *spte); 

#endif
